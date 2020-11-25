/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** sort fcts
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "my.h"
#include "my_ls.h"
#include "my_list.h"

static int name_chr_cmp(file_t *f1, file_t *f2)
{
    char *name1 = f1->name;
    char *name2 = f2->name;

    return (my_strcmp(name1, name2));
}

static int time_cmp(file_t *f1, file_t *f2)
{
    time_t time1 = (f1->statbuf->st_mtim).tv_sec;
    time_t time2 = (f2->statbuf->st_mtim).tv_sec;
    double diff = difftime(time2, time1);

    if (diff > 0)
        return (1);
    else
        return (0);
}

void sort_files(list_t *folders, int flags)
{
    list_t *folder;
    folder_t *fd;

    for (folder = folders; folder; folder = folder->next) {
        fd = (folder_t*) folder->data;
        my_sort_list(&(fd->files), &name_chr_cmp);
        if (flags & FLAG_TIME)
            my_sort_list(&(fd->files), &time_cmp);
    }
    if (flags & FLAG_REVERSE) {
        for (folder = folders; folder; folder = folder->next) {
            fd = (folder_t*) folder->data;
            my_rev_list(&(fd->files));
        }
    }
}