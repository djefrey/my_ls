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
#include "type_list.h"

static void print_sticky_bit(int mode, char id)
{
    if (id == 0) {
        if ((mode & S_ISUID))
            my_putchar('s');
        else
            my_putchar((mode & S_IXUSR) ? 'x' : '-');
    } else if (id == 1) {
        if ((mode & S_ISGID))
            my_putchar('s');
        else
            my_putchar((mode & S_IXGRP) ? 'x' : '-');
    } else {
        if ((mode & S_ISVTX))
            my_putchar('t');
        else
            my_putchar((mode & S_IXOTH) ? 'x' : '-');
    }
}

void print_type_and_permission(file_t *file)
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
    print_sticky_bit(mode, 0);
    my_putchar((mode & S_IRGRP) ? 'r' : '-');
    my_putchar((mode & S_IWGRP) ? 'w' : '-');
    print_sticky_bit(mode, 1);
    my_putchar((mode & S_IROTH) ? 'r' : '-');
    my_putchar((mode & S_IWOTH) ? 'w' : '-');
    print_sticky_bit(mode, 2);
}

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