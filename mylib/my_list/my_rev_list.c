/*
** EPITECH PROJECT, 2020
** my_rev_list
** File description:
** reverse the order of a linked list
*/

#include "my_list.h"
#include <stdlib.h>

void my_rev_list(list_t **begin)
{
    list_t *prev = NULL;
    list_t *actual = *begin;
    list_t *next = actual->next;

    while (next != NULL) {
        next = actual->next;
        actual->next = prev;
        prev = actual;
        actual = next;
    }
    *begin = prev;
}