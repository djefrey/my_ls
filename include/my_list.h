/*
** EPITECH PROJECT, 2020
** mylist.h
** File description:
** header file for linked list
*/

#ifndef MY_LIST_H
#define MY_LIST_H

typedef  struct  list {
    void *data;
    struct list *next;
} list_t;

void create_list(list_t **list, void *data);
void my_add_in_sorted_list(list_t **begin, void *data, int (*cmp)());
int my_apply_on_matching_nodes
(list_t *begin, int (*f)(), void const *data_ref, int (*cmp)());
int my_apply_on_nodes(list_t *begin , int (*f)(void *));
void my_concat_list(list_t **begin1, list_t *begin2);
int my_delete_node(list_t **begin, void *data);
int my_delete_nodes(list_t **begin, void const *data_ref, int (*cmp)());
list_t *my_find_node(list_t  *begin , void *data_ref , int (*cmp)());
int my_list_size(list_t *begin);
void my_merge(list_t **begin1, list_t *begin2, int (*cmp)());
void my_rev_list(list_t **begin);
list_t *get_smallest(list_t *cursor, int (*cmp)());
list_t *get_prev(list_t *element, list_t *list);
void move_element(list_t *element, list_t *cursor, list_t *list);
void my_sort_list(list_t **begin, int (*cmp)());

#endif
