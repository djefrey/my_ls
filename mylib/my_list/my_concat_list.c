/*
** EPITECH PROJECT, 2020
** my_concat_list
** File description:
** add the content of a second list at the end of a first list
*/

#include "my_list.h"
#include <stdlib.h>

void my_concat_list(list_t **begin1, list_t *begin2)
{
    list_t *list = *begin1;

    while (list->next != NULL)
        list = list->next;
    list->next = begin2;
}