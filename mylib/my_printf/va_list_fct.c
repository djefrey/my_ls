/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** va_list_fct
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void *va_list_char(va_list *arg)
{
    char value = va_arg(*arg, int);
    char *ptr = malloc(sizeof(char));

    *ptr = value;
    return ((void*) (ptr));
}

void *va_list_str(va_list *arg)
{
    char *value = va_arg(*arg, char*);
    char *ptr = my_strdup(value);

    return ((void*) (ptr));
}

void *va_list_ptr(va_list *arg)
{
    return ((void*) (va_arg(*arg, void*)));
}