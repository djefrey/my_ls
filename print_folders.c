/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** print_folders
*/

#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "my.h"
#include "my_ls.h"
#include "my_list.h"

static void print_folder_complete(folder_t *folder)
{
    list_t *files = folder->files;
    file_t *file;
    struct stat *stat;

    if (!folder->is_file)
        print_total_blocks(files);
    for (int i = 0; files != NULL; i++) {
        file = (file_t*) files->data;
        stat = file->statbuf;
        print_type_and_permission(file);
        my_printf(" %i %s %s %i ", stat->st_nlink,
        getpwuid(stat->st_uid)->pw_name, getgrgid(stat->st_gid)->gr_name,
        stat->st_size);
        my_printf("%.12s ", ctime(&(file->statbuf->st_mtim.tv_sec)) + 4);
        print_color(file);
        my_printf("%s\e[0m\n", file->name);
        files = files->next;
    }
}

static void print_folder_simple(folder_t *folder)
{
    list_t *files = folder->files;
    file_t *file;

    while (files != NULL) {
        file = (file_t*) files->data;
        print_color(file);
        my_putstr(file->name);
        my_putstr("\e[0m  ");
        files = files->next;
    }
    my_putchar('\n');
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
    } else {
        for (int i = 0; folders != NULL; i++, folders = folders->next) {
            folder = (folder_t*) folders->data;
            if (!folder->is_file)
                my_printf("%s:\n", folder->path);
            (*print_folder)(folder);
            if (i < n_folders - 1)
                my_putchar('\n');
        }
    }
}