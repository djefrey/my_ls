/*
** EPITECH PROJECT, 2020
** my_sort_int_array.c
** File description:
** sort array in ascending order
*/

static void move_digits(int *array, int start, int end)
{
    int *ptr;
    int *prev;

    for (int i = end; i > start; i--) {
        ptr = array + i;
        prev = ptr - 1;
        *ptr = *prev;
    }
}

static int get_smallest_pos(int *array, int cursor, int size)
{
    int *cursor_ptr = array + cursor;
    int smallest = *cursor_ptr;
    int smallest_pos = cursor;

    for (int i = cursor; i < size; i++) {
        int *ptr = array + i;
        if (smallest > *ptr) {
            smallest = *ptr;
            smallest_pos = i;
        }
    }
    return (smallest_pos);
}

static int get_value(int *array, int pos)
{
    int *ptr = array + pos;

    return *ptr;
}

void my_sort_int_array(int *array, int size)
{
    int cursor = 0;
    int *cursor_ptr = array;
    int smallest = *array;
    int smallest_pos = 0;

    while (cursor < size - 1) {
        smallest_pos = get_smallest_pos(array, cursor, size);
        smallest = get_value(array, smallest_pos);
        if (smallest_pos > cursor)
            move_digits(array, cursor, smallest_pos);
        *cursor_ptr = smallest;
        cursor++;
        cursor_ptr = array + cursor;
    }
}
