/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** return length of a string
*/

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0')
        length++;
    return (length);
}
