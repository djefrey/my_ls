/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** read folders
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_list.h"
#include "my_ls.h"

static void add_file_to_list(char *filepath, struct dirent *fileinfo,
list_t **list)
{
    file_t *file = malloc(sizeof(file_t));
    struct stat *statbuf = malloc(sizeof(struct stat));

    if (file == NULL) {
        free(file);
        return;
    }
    stat(filepath, statbuf);
    file->name = my_strdup(fileinfo->d_name);
    file->type = fileinfo->d_type;
    file->statbuf = statbuf;
    create_list(list, file);
}

static void add_folder_to_list(char *path, list_t *files, list_t **folders)
{
    folder_t *folder = malloc(sizeof(list_t));
    int pathlen = my_strlen(path);

    if (folder == NULL)
        return;
    folder->path = my_strdup(path);
    folder->path[pathlen - 1] = 0;
    folder->files = files;
    create_list(folders, folder);
}

static int get_files(char *path, int flags, list_t **folders, list_t **files)
{
    DIR *dir = opendir(path);
    int rec_folders = 0;
    struct dirent *fileinfo;
    char *filepath;

    if (dir != NULL) {
        while ((fileinfo = readdir(dir))) {
            if (fileinfo->d_name[0] == '.' && !(flags & FLAG_ALL))
                continue;
            filepath = my_strmerge(path, fileinfo->d_name);
            if (flags & FLAG_RECURSIVE && fileinfo->d_type == DT_DIR
            && my_strcmp(fileinfo->d_name, ".."))
                rec_folders += read_folder_content(filepath, folders, flags);
            add_file_to_list(filepath, fileinfo, files);
            free(filepath);
        }
        closedir(dir);
    }
    return (rec_folders);
}

int read_folder_content(char *path, list_t **folders, int flags)
{
    int n_folders = 1;
    int tmp = 0;
    list_t *files = NULL;
    char *newpath = my_strmerge(path, "/");

    if ((tmp = get_files(newpath, flags, folders, &files)) >= 0) {
        add_folder_to_list(newpath, files, folders);
        n_folders += tmp;
    } else
        perror(path);
    free(newpath);
    return (n_folders);
}

int read_folders(int ac, char *av[], list_t **folders, int flags)
{
    int n_folders = 0;
    int len;

    for (int i = 1; i < ac; i++) {
        if (*av[i] != '-') {
            len = my_strlen(av[i]);
            if (av[i][len - 1] == '/')
                av[i][len - 1] = 0;
            n_folders += read_folder_content(av[i], folders, flags);
        }
    }
    return (n_folders);
}