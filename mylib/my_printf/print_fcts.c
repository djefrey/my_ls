/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_fcts
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "nbr.h"
#include "flags_printf.h"
#include "printf_get_fcts.h"
#include "print_field_width.h"

int print_nb(void *value, int flags, int fwidth, int precision)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_nbr(nbr->sign, flags);
    int len = my_strlen(str);
    int offset = 0;
    int biggest = fwidth > precision ? fwidth : precision;

    flags = precision && flags & FLAG_ZERO ? flags - FLAG_ZERO : flags;
    if (flags & FLAG_ZERO && (str[0] == '+' || str[0] == '-')) {
        my_putchar(str[0]);
        offset = 1;
    }
    print_zeros_or_spaces(precision > len ?
    fwidth - precision : fwidth - len, flags);
    print_zeros(precision - len, FLAG_ZERO);
    my_putstr(str + offset);
    print_right_spaces(precision > len ?
    fwidth - precision : fwidth - len, flags);
    free(str);
    return (len > biggest ? len : biggest);
}

int print_char(void *value, int flags, int fwidth, int precision)
{
    flags = flags & FLAG_ZERO ? flags - FLAG_ZERO : flags;
    print_left_spaces(fwidth - 1, flags);
    my_putchar(*((char*) (value)));
    print_right_spaces(fwidth - 1, flags);
    return (fwidth > 1 ? fwidth : 1);
}

int print_str(void *value, int flags, int fwidth, int precision)
{
    char *str = (char*) (value);
    int len = my_strlen(str);
    int print_len = len > precision && precision > 0 ? precision : len;

    print_left_spaces(precision < len ?
    fwidth - precision : fwidth - len, flags);
    if (len > precision && precision > 0)
        write(1, str, precision);
    else
        write(1, str, len);
    print_right_spaces(precision < len ?
    fwidth - precision : fwidth - len, flags);
    return (print_len > fwidth ? print_len : fwidth);
}

int print_fullstr(void *value, int flags, int fwidth, int precision)
{
    char *str = printf_get_fullstr((char*) value);
    int len = my_strlen(str);
    int print_len = len > precision && precision > 0 ? precision : len;

    print_left_spaces(precision < len ?
    fwidth - precision : fwidth - len, flags);
    if (len > precision && precision > 0)
        write(1, str, precision);
    else
        write(1, str, len);
    print_right_spaces(precision < len ?
    fwidth - precision : fwidth - len, flags);
    return (print_len > fwidth ? print_len : fwidth);
}

int print_ptr(void *value, int flags, int fwidth, int precision)
{
    char *str = printf_get_nbr_base((long) (value), "0123456789abcdef", flags);
    int len = my_strlen(str) + 2;
    int offset = 0;
    int biggest = fwidth > precision ? fwidth : precision;

    if (fwidth > precision)
        print_left_spaces(precision > len ?
        fwidth - precision : fwidth - len, flags);
    if (*str == '+' || *str == ' ') {
        my_putchar(*str);
        offset = 1;
    }
    my_putstr("0x");
    print_zeros(precision > len ?
    fwidth - precision : fwidth - len, flags);
    print_zeros(precision - len, FLAG_ZERO);
    my_putstr(str + offset);
    print_right_spaces(precision > len ?
    fwidth - precision : fwidth - len, flags);
    free(str);
    return (len > biggest ? len : biggest);
}