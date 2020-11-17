/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** convert string as integer
*/

static int add_digit(char c, int nb, char sign)
{
    if (nb != 0)
        nb *= 10;
    nb += (c - 48) * sign;
    return (nb);
}

static char set_sign(char c, char sign)
{
    if (c == '+' && sign == -1)
        return (-1);
    else if (c == '-' && sign == 1)
        return (-1);
    else
        return (1);
}

static unsigned char check_prev_result(int nb, int prev_result)
{
    if (prev_result < 0 && nb > prev_result)
        return (1);
    else if (prev_result > 0 && nb < prev_result)
        return (1);
    else
        return (0);
}

static unsigned char is_valid_char(char c)
{
    if (c >= 48 && c <= 57)
        return (1);
    else if (c == '+' || c == '-')
        return (1);
    else
        return (0);
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int prev_result = 0;
    char sign = 1;

    while (*str != '\0' && is_valid_char(*str)) {
        if (*str >= 48 && *str <= 57)
            nb = add_digit(*str, nb, sign);
        else if ((*str == '-' || *str == '+') && nb ==0)
            sign = set_sign(*str, sign);
        str++;
        if (check_prev_result(nb, prev_result))
            return (0);
        prev_result = nb;
    }
    return (nb);
}
