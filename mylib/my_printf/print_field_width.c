/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print field width chars
*/

#include "my.h"
#include "flags_printf.h"

int print_zeros_or_spaces(int n, int flags)
{
    if (!(flags & FLAG_MINUS) && n > 0) {
        for (int i = 0; i < n; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
        return (1);
    }
    return (0);
}

int print_zeros(int n, int flags)
{
    if (!(flags & FLAG_MINUS) && (flags & FLAG_ZERO) && n > 0) {
        for (int i = 0; i < n; i++)
            my_putchar('0');
        return (1);
    }
    return (0);
}

int print_left_spaces(int n, int flags)
{
    if (!(flags & FLAG_MINUS) && !(flags & FLAG_ZERO) && n > 0) {
        for (int i = 0; i < n; i++)
            my_putchar(' ');
        return (1);
    }
    return (0);
}

int print_right_spaces(int n, int flags)
{
    if ((flags & FLAG_MINUS) && n > 0) {
        for (int i = 0; i < n; i++)
            my_putchar(' ');
        return (1);
    }
    return (0);
}