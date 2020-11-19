/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** read_args
*/

#include "flag_list.h"

static int add_flags(char *av)
{
    int flags = 0;

    while (*av) {
        for (int i = 0; i < NUMBER_FLAGS; i++) {
            if (*av == FLAGS_LS[i]) {
                flags += FLAGS_LS_VALUE[i];
                break;
            }
        }
        av++;
    }
    return (flags);
}

int get_flags(int ac, char *av[])
{
    int flags = 0;

    for (int i = 1; i < ac; i++) {
        if (*av[i] == '-')
            flags += add_flags(av[i]);
    }
    return (flags);
}