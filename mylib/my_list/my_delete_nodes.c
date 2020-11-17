/*
** EPITECH PROJECT, 2020
** my_delete_nodes
** File description:
** remove all nodes with data matching
*/

#include <stdlib.h>
#include "my_list.h"

int my_delete_node(list_t **begin, void *data)
{
    list_t *prev = NULL;
    list_t *actual = *begin;
    list_t *next = actual->next;

    while (actual != NULL) {
        next = actual->next;
        if (actual->data == data) {
            if (prev != NULL)
                prev->next = next;
            else
               *begin = next;
            return (0);
        } else
            prev = actual;
        actual = next;
    }
    return (0);
}

int my_delete_nodes(list_t **begin, void const *data_ref, int (*cmp)())
{
    list_t *prev = NULL;
    list_t *actual = *begin;
    list_t *next = actual->next;

    while (actual != NULL) {
        next = actual->next;
        if ((*cmp)(actual->data, data_ref) == 0) {
            if (prev != NULL)
                prev->next = next;
            else
               *begin = next;
        } else
            prev = actual;
        actual = next;
    }
    return (0);
}