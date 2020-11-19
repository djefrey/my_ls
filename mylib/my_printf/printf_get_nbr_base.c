/*
** EPITECH PROJECT, 2020
** my_putnbr_base
** File description:
** convert and display an integer into a number in a given base
*/

#include <stdlib.h>
#include "my.h"
#include "flags_printf.h"

static void add_sign(long long *nb, char *str, int length, int flags)
{
    if (*nb < 0) {
        str[length] = '-';
        *nb *= -1;
    } else if (flags & FLAG_BLANK || flags & FLAG_SIGN) {
        if (flags & FLAG_SIGN)
            str[length] = '+';
        else
            str[length] = ' ';
    } else
        str[length] = 0;
}

static unsigned long long get_nbr_len(unsigned long long nb, int base_size)
{
    unsigned long long length = 0;

    if (nb == 0)
        return (1);
    while (nb > 0) {
        nb = nb / base_size;
        length++;
    }
    return (length);
}

char *printf_get_nbr_base(long long nb, char const *base, int flags)
{
    int base_size = my_strlen(base);
    int remainder = 0;
    unsigned long long length = get_nbr_len(nb < 0 ? -nb : nb, base_size);
    char *str = malloc(sizeof(char) * (length + 1));

    str[length] = 0;
    add_sign(&nb, str, length, flags);
    for (int i = 0; nb > 0; i++) {
        remainder = nb % base_size;
        str[i] = base[remainder];
        nb = nb / base_size;
    }
    my_revstr(str);
    return (str);
}

char *printf_get_unbr_base(unsigned long long nb, char const *base)
{
    int base_size = my_strlen(base);
    int remainder = 0;
    unsigned long long length = get_nbr_len(nb, base_size);
    char *str = malloc(sizeof(char) * (length + 1));

    str[length] = 0;
    for (int i = 0; nb > 0; i++) {
        remainder = nb % base_size;
        str[i] = base[remainder];
        nb = nb / base_size;
    }
    my_revstr(str);
    return (str);
}