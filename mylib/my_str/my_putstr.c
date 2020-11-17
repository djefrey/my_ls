/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** print each character of a string
*/

#include "my.h"

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (0);
}