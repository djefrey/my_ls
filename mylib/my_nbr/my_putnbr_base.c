/*
** EPITECH PROJECT, 2020
** my_putnbr_base
** File description:
** convert and display an integer into a number in a given base
*/

#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int base_size = my_strlen(base);
    int quotient = nbr;
    int remainder = 0;
    char str[32] = {0};
    int length = 0;

    if (my_isneg(nbr)) {
        nbr *= -1;
        quotient *= -1;
    }
    while (quotient > 0) {
        quotient = nbr / base_size;
        remainder = nbr - quotient * base_size;
        str[length] = base[remainder];
        nbr = quotient;
        length++;
    }
    for (int i = length; i >= 0; i--)
        my_putchar(str[i]);
    return (0);
}
