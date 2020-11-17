/*
** EPITECH PROJECT, 2020
** my_apply_on_nodes
** File description:
** apply a given function to every node
*/

#include "my_list.h"
#include <stdlib.h>

int my_apply_on_nodes(list_t *begin , int (*f)(void *))
{
    list_t *list = begin;

    while (list != NULL) {
        (*f)(list->data);
        list = list->next;
    }
    return (0);
}