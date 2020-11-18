/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** main
*/

#include <stdlib.h>
#include "my_ls.h"
#include "my_list.h"

static void delete_files(list_t *files)
{
    list_t *next;
    file_t *file;

    while (files != NULL) {
        next = files->next;
        file = (file_t*) files->data;
        free(file->statbuf);
        free(file);
        free(files);
        files = next;
    }
}

static void delete_folders(list_t *folders)
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

int main(int ac, char *av[])
{
    int flags = get_flags(ac, av);
    list_t *folders = NULL;
    int n_folders = read_folders(ac, av, &folders, flags);

    print_folders(folders, n_folders, flags);
    delete_folders(folders);
    return (0);
}