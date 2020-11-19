/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** conversion
*/

#include <stdarg.h>
#include "my.h"
#include "printf.h"
#include "printf_values.h"

static void check_flags_and_modifiers(char **str, int *flags,
va_list_fct_t *length_modif)
{
    for (int i = 0; i < NUMBER_FLAGS; i++) {
        if (**str == FLAGS_PRINTF[i]) {
            if (FLAG_PRINTF_VALUES[i] == FLAG_MINUS && *flags & FLAG_ZERO)
                *flags -= FLAG_ZERO;
            else if (FLAG_PRINTF_VALUES[i] == FLAG_SIGN && *flags & FLAG_BLANK)
                *flags -= FLAG_BLANK;
            *flags += FLAG_PRINTF_VALUES[i];
            *str += 1;
            i = -1;
        }
    }
    for (int i = 0; i < NUMBER_MODIFIERS; i++) {
        if (!my_strcmp(*str, MODIFIERS[i])) {
            *length_modif = VA_LIST_MOD[i];
            *str += my_strlen(MODIFIERS[i]);
            break;
        }
    }
}

static int check_special_flags(char **str,  va_list *list, int *length)
{
    int *ptr;

    if (**str == '%') {
        my_putchar('%');
        *str += 1;
        *length += 1;
        return (1);
    } else if (**str == 'n') {
        ptr = va_arg(*list, int*);
        *ptr = (int) *length;
        *str += 1;
        return (1);
    }
    return (0);
}

static int check_precision(char **str)
{
    int precision = 0;

    if (**str == '.') {
        *str += 1;
        while (**str >= '0' && **str <= '9') {
            precision = precision * 10 + (**str - 48);
            *str += 1;
        }
    }
    return (precision);
}

static int check_specifier(char **str, va_list *list,
int *len, info_printf_t infos)
{
    void *value = NULL;

    for (int i = 0; i < NUMBER_SPECIFIERS; i++) {
        if (**str == SPECIFIERS[i]) {
            value = VA_LIST_SPEC[i] != NULL ?
            VA_LIST_SPEC[i](list) : (*(infos.length_modif))(list);
            *len += PRINT_FCTS[i](value, infos.flags,
            infos.field_width, infos.precision);
            if (i != FLAG_PTR_ID)
                free(value);
            *str += 1;
            return (1);
        }
    }
    return (0);
}

int printf_conversion(char **str, va_list *list, int *length)
{
    info_printf_t infos;
    infos.length_modif = &va_list_nbint;

    infos.flags = 0;
    infos.field_width = 0;
    infos.precision = 0;
    check_flags_and_modifiers(str, &infos.flags, &infos.length_modif);
    while (**str >= '0' && **str <= '9') {
        infos.field_width =
        infos.field_width * 10 + (**str - 48);
        *str += 1;
    }
    infos.precision = check_precision(str);
    if (check_special_flags(str, list, length))
        return (1);
    else if (check_specifier(str, list, length, infos))
        return (1);
    return (0);
}
