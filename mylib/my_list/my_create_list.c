/*
** EPITECH PROJECT, 2020
** my_create_list
** File description:
** create a list
*/

 #include <stdlib.h>
 #include "my_list.h"

void create_list(list_t **list, void *data)
{
    list_t *element = malloc(sizeof(list_t));

    element->data = data;
    element->next = *list;
    *list = element;
}