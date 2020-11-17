/*
** EPITECH PROJECT, 2020
** swap.c
** File description:
** swap the content of two int pointers
*/

void my_intswap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
