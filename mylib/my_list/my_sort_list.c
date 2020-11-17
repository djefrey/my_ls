/*
** EPITECH PROJECT, 2020
** my_sort_list
** File description:
** sort list in ascneding order by comparing data
*/

#include "my_list.h"
#include <stdlib.h>
#include "my.h"

list_t *get_smallest(list_t *cursor, int (*cmp)())
{
    list_t *smallest = cursor;

    while (cursor != NULL) {
        if ((*cmp)(smallest->data, cursor->data) > 0) {
            smallest = cursor;
        }
        cursor = cursor->next;
    }
    return (smallest);
}

list_t *get_prev(list_t *element, list_t *list)
{
    while (list != NULL && list->next != NULL) {
        if (list->next == element)
            return (list);
        list = list->next;
    }
    return (NULL);
}

void move_element(list_t *element, list_t *cursor, list_t *list)
{
    list_t *prev = get_prev(element, list);
    list_t *prev_cursor = get_prev(cursor, list);

    if (prev != NULL)
        prev->next = element->next;
    if (prev_cursor != NULL)
        prev_cursor->next = element;
    element->next = cursor;
}

void my_sort_list(list_t **begin, int (*cmp)())
{
    int size = my_list_size(*begin);
    list_t *cursor = *begin;
    list_t *smallest = NULL;

    for (int i = 0; i < size; i++) {
        smallest = get_smallest(cursor, cmp);
        if (cursor == smallest)
            cursor = cursor->next;
        else
            move_element(smallest, cursor, *begin);
        if (i == 0)
            *begin = smallest;
    }
}