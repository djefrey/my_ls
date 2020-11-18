/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** print_fcts
*/

#include <dirent.h>
#include "my.h"
#include "my_ls.h"
#include "colors_list.h"

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