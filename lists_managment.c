/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** lists managment
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "my.h"
#include "my_list.h"
#include "my_ls.h"

static void delete_files(list_t *files)
{
    list_t *next;
    file_t *file;

    while (files != NULL) {
        next = files->next;
        file = (file_t*) files->data;
        free(file->name);
        free(file->statbuf);
        free(file);
        free(files);
        files = next;
    }
}

void delete_folders(list_t *folders)
{
    list_t *next;
    folder_t *folder;

    while (folders != NULL) {
        next = folders->next;
        folder = (folder_t*) folders->data;
        delete_files(folder->files);
        free(folder->path);
        free(folder);
        free(folders);
        folders = next;
    }
}

void add_file_to_list(char *filepath, struct dirent *fileinfo, list_t **list)
{
    file_t *file = malloc(sizeof(file_t));
    struct stat *statbuf = malloc(sizeof(struct stat));
    char type;

    if (file == NULL) {
        free(file);
        return;
    }
    stat(filepath, statbuf);
    type = fileinfo == NULL ? statbuf->st_mode & S_IFMT : fileinfo->d_type;
    file->name = my_strdup(fileinfo == NULL ? filepath : fileinfo->d_name);
    file->type = type;
    file->statbuf = statbuf;
    create_list(list, file);
}

void add_folder_to_list(char *path, list_t *files, list_t **folders,
unsigned char is_file)
{
    folder_t *folder = malloc(sizeof(list_t));
    int pathlen = my_strlen(path);

    if (folder == NULL)
        return;
    folder->is_file = is_file;
    folder->path = my_strdup(path);
    folder->path[pathlen - 1] = 0;
    folder->files = files;
    create_list(folders, folder);
}