/*
** EPITECH PROJECT, 2020
** is_valid_int
** File description:
** return if long is a valid int
*/

unsigned char is_valid_int(long value)
{
    return (value >= -2147483648 && value <= 2147483647);
}
