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
#include "my.h"
#include "my_list.h"
#include "my_ls.h"

static void add_file_to_list(char *filepath, struct dirent *fileinfo,
list_t **files)
{
    file_t *file = malloc(sizeof(file_t));
    struct stat *statbuf = malloc(sizeof(struct stat));

    if (file == NULL) {
        free(file);
        return;
    }
    stat(filepath, statbuf);
    file->file = fileinfo;
    file->statbuf = statbuf;
    create_list(files, file);
}

static void add_folder_to_list(char *path, list_t *files, list_t **folders)
{
    folder_t *folder = malloc(sizeof(list_t));

    if (folder == NULL)
        return;
    folder->path = my_strdup(path);
    folder->files = files;
    create_list(folders, folder);
}

static int read_content(char *path, list_t **folders, int flags)
{
    int n_folders = 1;
    DIR *dir = opendir(path);
    struct dirent *fileinfo;
    char *filepath;
    list_t *files = NULL;

    if (dir != NULL) {
        while ((fileinfo = readdir(dir))) {
            if (fileinfo->d_name[0] == '.' && !(flags & FLAG_ALL))
                continue;
            filepath = my_strmerge(path, fileinfo->d_name);
            my_strinsert(&filepath, "/", my_strlen(path));
            printf("=> (%s)/%s - %s\n", path, fileinfo->d_name, filepath);
            if (flags & FLAG_RECURSIVE && fileinfo->d_type == DT_DIR)
                n_folders += read_content(filepath, folders, flags);
            add_file_to_list(filepath, fileinfo, &files);
            free(filepath);
        }
        add_folder_to_list(path, files, folders);
    } else
        perror(path);
    closedir(dir);
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
            n_folders += read_content(av[i], folders, flags);
        }
    }
    return (n_folders);
}