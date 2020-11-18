/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** print_folders
*/

#include <stdlib.h>
#include <dirent.h>
#include "my_ls.h"
#include "my_list.h"

static void print_folder_complete(list_t *files)
{
    file_t *file;

    for (int i = 0; files != NULL; i++) {
        file = (file_t*) files->data;
        my_putstr(file->file->d_name);
        files = files->next;
    }
}

static void print_folder_simple(list_t *files)
{
    file_t *file;

    for (int i = 0; files != NULL; i++) {
        file = (file_t*) files->data;
        if (i > 0)
            my_putstr("  ");
        my_putstr(file->file->d_name);
        files = files->next;
    }
}

static print_folder_t get_print_fct(int flags)
{
    if (flags & FLAG_LIST)
        return (&print_folder_complete);
    else
        return (&print_folder_simple);
}

void print_folders(list_t *folders, int n_folders, int flags)
{
    print_folder_t print_folder = get_print_fct(flags);
    folder_t *folder;

    if (n_folders == 1) {
        folder = (folder_t*) folders->data;
        (*print_folder)(folder->files);
        my_putchar('\n');
    } else {
        for (int i = 0; folders != NULL; i++) {
            folder = (folder_t*) folders->data;
            my_putstr(folder->path);
            my_putstr(":\n");
            (*print_folder)(folder->files);
            my_putchar('\n');
            if (i < n_folders - 1)
                my_putchar('\n');
            folders = folders->next;
        }
    }
}