/*
** EPITECH PROJECT, 2020
** my_find_node
** File description:
** return the first node matching
*/

#include "my_list.h"
#include <stdlib.h>

list_t *my_find_node(list_t  *begin , void *data_ref , int (*cmp)())
{
    list_t *list = begin;

    while (list != NULL) {
        if ((*cmp)(list->data, data_ref) == 0)
            return (list);
        list = list->next;
    }
    return (NULL);
}