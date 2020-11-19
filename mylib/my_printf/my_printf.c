/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include <stdlib.h>
#include "printf.h"
#include "my.h"

int my_vprintf(char *str, va_list arg_list)
{
    int length = 0;
    va_list arg_cpy;

    va_copy(arg_cpy, arg_list);
    while (*str) {
        if (*str == '%') {
            str += 1;
            if (!printf_conversion(&str, &arg_cpy, &length)) {
                my_putchar('%');
                my_putchar(*str);
                str += 1;
                length += 2;
            }
        } else {
            my_putchar(*str);
            str += 1;
            length += 1;
        }
    }
    return (length);
}

int my_printf(char *str, ...)
{
    va_list arg_list;
    int length;

    va_start(arg_list, str);
    length = my_vprintf(str, arg_list);
    va_end(arg_list);
    return (length);
}