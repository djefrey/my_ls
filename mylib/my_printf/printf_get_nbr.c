/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print number that is provided
*/

#include <stdlib.h>
#include "my.h"
#include "flags_printf.h"

static char add_sign(long long nb, char *str, int flags)
{
    if (nb < 0) {
        str[0] = '-';
    } else if (flags & FLAG_BLANK || flags & FLAG_SIGN) {
        if (flags & FLAG_SIGN)
            str[0] = '+';
        else
            str[0] = ' ';
    } else {
        return (0);
    }
    return (1);
}

static unsigned long long get_nbr_length(unsigned long long nb)
{
    unsigned long long length = 0;

    if (nb == 0)
        return (1);
    while (nb > 0) {
        nb /= 10;
        length++;
    }
    return (length);
}

char *printf_get_nbr(long long nb, int flags)
{
    char digit;
    unsigned long long unb = nb < 0 ? -nb : nb;
    unsigned long long length = get_nbr_length(unb);
    char *str = malloc(sizeof(char) * (length + 2));
    int start = 1;
    int end = length;

    str[length + 1] = 0;
    if (!add_sign(nb, str, flags)) {
        str[length] = 0;
        start = 0;
        end = length - 1;
    }
    for (int i = 0; start + i <= end; i++) {
        digit = unb % 10;
        str[end - i] = digit + 48;
        unb /= 10;
    }
    return (str);
}

char *printf_get_unbr(unsigned long long unb)
{
    int digit;
    unsigned long long length = get_nbr_length(unb);
    char *str = malloc(sizeof(char) * (length + 1));

    str[length] = 0;
    for (int i = length - 1; i >= 0; i--) {
        digit = unb % 10;
        str[i] = digit + 48;
        unb /= 10;
    }
    return (str);
}