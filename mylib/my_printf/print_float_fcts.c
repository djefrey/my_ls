/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** printf_float_fcts
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "flags_printf.h"
#include "print_field_width.h"
#include "printf_get_fcts.h"

void *va_list_double(va_list *arg)
{
    double value = (double) (va_arg(*arg, double));
    double *ptr = malloc(sizeof(double));

    *ptr = value;
    return (ptr);
}

int print_double(void *value, int flags, int fwidth, int precision)
{
    char *str =printf_get_float(*((double*) (value)), flags, precision);
    int len = my_strlen(str);
    int offset = 0;

    if (flags & FLAG_ZERO && (str[0] == '+' || str[0] == '-')) {
        my_putchar(str[0]);
        offset = 1;
    }
    print_zeros_or_spaces(fwidth - len, flags);
    my_putstr(str + offset);
    print_right_spaces(fwidth - len, flags);
    free(str);
    return (len > fwidth ? len : fwidth);
}