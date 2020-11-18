/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** print_folders
*/

#include <stdlib.h>
#include <dirent.h>
#include "my.h"
#include "my_ls.h"
#include "my_list.h"

static void print_folder_complete(folder_t *folder)
{
    list_t *files = folder->files;
    file_t *file;

    for (int i = 0; files != NULL; i++) {
        file = (file_t*) files->data;
        my_putstr(file->name);
        files = files->next;
    }
}

static void print_folder_simple(folder_t *folder)
{
    list_t *files = folder->files;
    file_t *file;

    for (int i = 0; files != NULL; i++) {
        file = (file_t*) files->data;
        if (i > 0)
            my_putstr("  ");
        print_color(file);
        my_putstr(file->name);
        my_putstr("\e[0m");
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
        (*print_folder)(folder);
        my_putchar('\n');
    } else {
        for (int i = 0; folders != NULL; i++, folders = folders->next) {
            folder = (folder_t*) folders->data;
            my_putstr(folder->path);
            my_putstr(":\n");
            (*print_folder)(folder);
            my_putchar('\n');
            if (i < n_folders - 1)
                my_putchar('\n');
        }
    }
}