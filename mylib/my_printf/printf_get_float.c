/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** get float
*/

#include <stdlib.h>
#include "my.h"
#include "flags_printf.h"
#include "printf_get_fcts.h"

static char *add_float_digits(double nb, int float_len)
{
    double float_nbrs = nb - ((long long) nb);
    char *str = malloc(sizeof(char) * (float_len + 2));

    if (str == NULL)
        return (NULL);
    str[0] = '.';
    str[float_len] = 0;
    for (int i = 0; i < float_len; i++) {
        float_nbrs = float_nbrs * 10.0;
        str[i + 1] = (char) (float_nbrs) + 48;
        float_nbrs -= (char) (float_nbrs);
    }
    return (str);
}

char *printf_get_float(double nb, int flags, int precision)
{
    char *nbr_str = printf_get_nbr((long long) nb, flags);
    int nbr_len = my_strlen(nbr_str);
    int float_len = precision == 0 ? 6 : precision;
    char *float_str = add_float_digits(nb < 0 ? -nb : nb, float_len);
    char *str = malloc(sizeof(char) * (nbr_len + float_len + 1));

    str[nbr_len + float_len] = 0;
    my_strcpy(str, nbr_str);
    my_strcpy(str + nbr_len, float_str);
    free(nbr_str);
    free(float_str);
    return (str);
}