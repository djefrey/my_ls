/*
** EPITECH PROJECT, 2020
** my_list_size
** File description:
** return the number of elements on the list
*/

#include "my_list.h"
#include <stdlib.h>

int my_list_size(list_t *begin)
{
    int size = 0;
    list_t *list = begin;

    while (list != NULL) {
        size++;
        list = list->next;
    }
    return (size);
}