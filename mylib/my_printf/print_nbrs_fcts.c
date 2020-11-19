/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_fcts
*/

#include <stdlib.h>
#include "my.h"
#include "nbr.h"
#include "flags_printf.h"
#include "printf_get_fcts.h"
#include "print_field_width.h"

int print_unnb(void *value, int flags, int fwidth, int precision)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr(nbr->unsign);
    int len = my_strlen(str);
    int biggest = fwidth > precision ? fwidth : precision;

    flags = precision && flags & FLAG_ZERO ? flags - FLAG_ZERO : flags;
    print_zeros_or_spaces(precision > len ?
    fwidth - precision : fwidth - len, flags);
    print_zeros(precision - len, FLAG_ZERO);
    my_putstr(str);
    print_right_spaces(precision > len ?
    fwidth - precision : fwidth - len, flags);
    free(str);
    return (len > biggest ? len : biggest);
}

int print_octal(void *value, int flags, int fwidth, int precision)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr_base(nbr->unsign, "01234567");
    int len = my_strlen(str) + (flags & FLAG_HASHTAG);
    int biggest = fwidth > precision ? fwidth : precision;

    flags = precision && flags & FLAG_ZERO ? flags - FLAG_ZERO : flags;
    print_zeros_or_spaces(precision > len ?
    fwidth - precision : fwidth - len, flags);
    print_zeros(precision - len, FLAG_ZERO);
    if (flags & FLAG_HASHTAG)
        my_putchar('0');
    my_putstr(str);
    print_right_spaces(precision > len ?
    fwidth - precision : fwidth - len, flags);
    free(str);
    return (len > biggest ? len : biggest);
}

int print_binary(void *value, int flags, int fwidth, int precision)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr_base(nbr->unsign, "01");
    char len = my_strlen(str) + (flags & FLAG_HASHTAG);
    int biggest = fwidth > precision ? fwidth : precision;

    precision = precision ? precision + (flags & FLAG_HASHTAG) : 0;
    flags = precision && flags & FLAG_ZERO ? flags - FLAG_ZERO : flags;
    if (fwidth > precision)
        print_left_spaces(precision > len ?
        fwidth - precision : fwidth - len, flags);
    if (flags & FLAG_HASHTAG)
        my_putchar('b');
    print_zeros(precision > len ?
    fwidth - precision : fwidth - len, flags);
    print_zeros(precision - len, FLAG_ZERO);
    my_putstr(str);
    print_right_spaces(precision > len ?
    fwidth - precision : fwidth - len, flags);
    free(str);
    return (len > biggest ? len : biggest);
}

int print_hexa(void *value, int flags, int fwidth, int precision)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr_base(nbr->unsign, "0123456789abcdef");
    int len = my_strlen(str) + (flags & FLAG_HASHTAG) * 2;
    int biggest = fwidth > precision ? fwidth : precision;

    precision = precision ? precision + (flags & FLAG_HASHTAG) * 2 : 0;
    flags = precision && flags & FLAG_ZERO ? flags - FLAG_ZERO : flags;
    if (fwidth > precision)
        print_left_spaces(precision > len ?
        fwidth - precision : fwidth - len, flags);
    if (flags & FLAG_HASHTAG)
        my_putstr("0x");
    print_zeros(precision > len ? fwidth - precision : fwidth - len, flags);
    print_zeros(precision - len, FLAG_ZERO);
    my_putstr(str);
    print_right_spaces(precision > len ?
    fwidth - precision : fwidth - len, flags);
    free(str);
    return (len > biggest ? len : biggest);
}

int print_uphexa(void *value, int flags, int fwidth, int precision)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr_base(nbr->unsign, "0123456789ABCDEF");
    int len = my_strlen(str) + (flags & FLAG_HASHTAG) * 2;
    int biggest = fwidth > precision ? fwidth : precision;

    precision = precision ? precision + (flags & FLAG_HASHTAG) * 2 : 0;
    flags = precision && flags & FLAG_ZERO ? flags - FLAG_ZERO : flags;
    if (fwidth > precision)
        print_left_spaces(precision > len ?
        fwidth - precision : fwidth - len, flags);
    if (flags & FLAG_HASHTAG)
        my_putstr("0X");
    print_zeros(precision > len ? fwidth - precision : fwidth - len, flags);
    print_zeros(precision - len, FLAG_ZERO);
    my_putstr(str);
    print_right_spaces(precision > len ?
    fwidth - precision : fwidth - len, flags);
    free(str);
    return (len > biggest ? len : biggest);
}