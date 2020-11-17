/*
** EPITECH PROJECT, 2020
** my_apply_on_matching_nodes
** File description:
** apply a given function to every node matching
*/

#include "my_list.h"
#include <stdlib.h>

int my_apply_on_matching_nodes
(list_t *begin, int (*f)(), void const *data_ref, int (*cmp)())
{
    list_t *list = begin;

    while (list != NULL) {
        if ((*cmp)(list->data, data_ref) == 0)
            (*f)(list->data);
        list = list->next;
    }
    return (0);
}
