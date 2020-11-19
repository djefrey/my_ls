/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** va_list_fct
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "nbr.h"

void *va_list_nbchar(va_list *arg)
{
    char value = (char) (va_arg(*arg, int));
    nbr_t *nbr_ptr = malloc(sizeof(nbr_t));

    nbr_ptr->unsign = (unsigned char) value;
    nbr_ptr->sign = (char) value;
    return (nbr_ptr);
}

void *va_list_nbshort(va_list *arg)
{
    short value = (short) (va_arg(*arg, int));
    nbr_t *nbr_ptr = malloc(sizeof(nbr_t));

    nbr_ptr->unsign = (unsigned short) value;
    nbr_ptr->sign = (short) value;
    return (nbr_ptr);
}

void *va_list_nbint(va_list *arg)
{
    int value = (int) (va_arg(*arg, int));
    nbr_t *nbr_ptr = malloc(sizeof(nbr_t));

    nbr_ptr->unsign = (unsigned int) value;
    nbr_ptr->sign = (int) value;
    return (nbr_ptr);
}

void *va_list_nblong(va_list *arg)
{
    long value = (long) (va_arg(*arg, long));
    nbr_t *nbr_ptr = malloc(sizeof(nbr_t));

    nbr_ptr->unsign = (unsigned long) value;
    nbr_ptr->sign = (long) value;
    return (nbr_ptr);
}

void *va_list_nblonglong(va_list *arg)
{
    long long value = (long long) (va_arg(*arg, long long));
    nbr_t *nbr_ptr = malloc(sizeof(nbr_t));

    nbr_ptr->unsign = (unsigned long long) value;
    nbr_ptr->sign = (long long) value;
    return (nbr_ptr);
}