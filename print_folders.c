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
#include "type_list.h"

static void print_type_and_permission(file_t *file)
{
    int mode = file->statbuf->st_mode;

    for (int i = 0; i < NUMBER_TYPE; i++) {
        if ((mode & S_IFMT) == TYPE_LS[i]) {
            my_putchar(TYPE_LS_VALUE[i]);
            break;
        }
    }
    my_putchar((mode & S_IRUSR) ? 'r' : '-');
    my_putchar((mode & S_IWUSR) ? 'w' : '-');
    my_putchar((mode & S_IXUSR) ? 'x' : '-');
    my_putchar((mode & S_IRGRP) ? 'r' : '-');
    my_putchar((mode & S_IWGRP) ? 'w' : '-');
    my_putchar((mode & S_IXGRP) ? 'x' : '-');
    my_putchar((mode & S_IROTH) ? 'r' : '-');
    my_putchar((mode & S_IWOTH) ? 'w' : '-');
    my_putchar((mode & S_IXOTH) ? 'x' : '-');
}

static void print_folder_complete(folder_t *folder)
{
    list_t *files = folder->files;
    file_t *file;
    struct stat *stat;
    struct passwd *user;
    struct group *grp;

    my_printf("total %i\n", -1);
    for (int i = 0; files != NULL; i++) {
        file = (file_t*) files->data;
        stat = file->statbuf;
        user = getpwuid(stat->st_uid);
        grp = getgrgid(stat->st_gid);
        print_type_and_permission(file);
        my_printf(" %i %s %s %ld ", stat->st_nlink, user->pw_name,
        grp->gr_name, stat->st_size);
        my_printf("%.12s ", ctime(&(file->statbuf->st_ctim.tv_sec)) + 4);
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
        my_putstr("\e[0m\n");
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
    } else {
        for (int i = 0; folders != NULL; i++, folders = folders->next) {
            folder = (folder_t*) folders->data;
            my_printf("%s:\n", folder->path);
            (*print_folder)(folder);
            if (i < n_folders - 1)
                my_putchar('\n');
        }
    }
}