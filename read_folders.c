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
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "my_list.h"
#include "my_ls.h"

static int get_file(char *path, list_t **files, DIR *dir)
{
    struct stat statbuf;

    if (dir != NULL)
        closedir(dir);
    path[my_strlen(path) - 1] = 0;
    if (stat(path, &statbuf) == -1)
        return (0);
    add_file_to_list(path, NULL, files);
    return (1);
}

static int get_files(char *path, int flags, list_t **folders, list_t **files)
{
    DIR *dir = opendir(path);
    int rec_folders = 0;
    struct dirent *fileinfo;
    char *filepath;

    if (dir != NULL && !(flags & FLAG_DIR)) {
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
        return (rec_folders);
    } else if (get_file(path, files, dir))
        return (-1);
    return (-2);
}

int read_folder_content(char *path, list_t **folders, int flags)
{
    int n_folders = 1;
    int ret_value = 0;
    list_t *files = NULL;
    char *newpath = my_strmerge(path, "/");
    char *error_part;
    char *error;

    if ((ret_value = get_files(newpath, flags, folders, &files)) >= -1) {
        add_folder_to_list(newpath, files, folders, ret_value == - 1 ? 1 : 0);
        n_folders += ret_value == -1 ? 0 : ret_value;
    } else {
        error_part = my_strmerge("./my_ls: cannot access '", path);
        error = my_strmerge(error_part, "'");
        perror(error);
        free(error);
        free(error_part);
    }
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