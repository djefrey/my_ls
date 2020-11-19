/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_get_fullstr
*/

#include <stdlib.h>
#include "my.h"
#include "printf_get_fcts.h"

static int get_fullstr_length(char *str)
{
    int length = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] >= 32)
            length++;
        else
            length += 4;
    }
    return (length);
}

static void add_octal_value(char c, char *result, int *pos)
{
    char *nbr_str = printf_get_unbr_base(c, "01234567");
    int nbr_len = my_strlen(nbr_str);

    result[*pos] = '\\';
    for (int j = 0; j < 3; j++)
        result[*pos + 1 + j] = (j + nbr_len) - 3 >= 0 ?
        nbr_str[(j + nbr_len) - 3] : '0';
    *pos += 3;
    free(nbr_str);
}

char *printf_get_fullstr(char *str)
{
    int length = get_fullstr_length(str);
    char *result = malloc(sizeof(char) * (length + 1));
    int pos = 0;

    result[length] = 0;
    for (int i = 0; str[i]; i++, pos++) {
        if (str[i] >= 32 && str[i] < 127)
            result[pos] = str[i];
        else
            add_octal_value(str[i], result, &pos);
    }
    return (result);
}