/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** print_fcts
*/

#include <unistd.h>
#include "my.h"
#include "my_ls.h"
#include "colors_list.h"

void print_total_blocks(list_t *files)
{
    file_t *file;
    int total = 0;

    while (files != NULL) {
        file = (file_t*) files->data;
        total += file->statbuf->st_blocks / 2;
        files = files->next;
    }
    my_printf("total %i\n", total);
}

void print_color(file_t *file)
{
    int len = my_strlen(file->name);
    int mode = file->statbuf->st_mode;

    for (int i = 0; i < NUMBER_COLORS; i++) {
        if ((mode & S_IFMT) == COLORS_TYPE[i]) {
            my_putstr(COLORS[i]);
            return;
        }
    }
    if (mode & S_IXUSR) {
        my_putstr(EXEC_COLOR);
        return;
    }
}