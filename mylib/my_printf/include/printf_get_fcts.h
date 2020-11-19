/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_print_nbr
*/

#ifndef MY_PRINT_NBR_H_
#define MY_PRINT_NBR_H_

char *printf_get_fullstr(char *str);

char *printf_get_nbr(long long nb, int flags);
char *printf_get_unbr(unsigned long long nb);
char *printf_get_nbr_base(long long nb, char const *base, int flags);
char *printf_get_unbr_base(unsigned long long nb, char const *base);

char *printf_get_float(double nb, int flags, int precision);

#endif /* !MY_PRINT_NBR_H_ */