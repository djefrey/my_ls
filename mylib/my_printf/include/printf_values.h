/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** printf_values
*/

#ifndef PRINTF_VALUES_H_
#define PRINTF_VALUES_H_

#define NUMBER_FLAGS 5
#define NUMBER_MODIFIERS 7
#define NUMBER_SPECIFIERS 12
#define FLAG_PTR_ID 0

const char FLAGS_PRINTF[] = {'#', '0', '-', ' ', '+'};

const char FLAG_PRINTF_VALUES[] = {FLAG_HASHTAG, FLAG_ZERO, FLAG_MINUS,
                            FLAG_BLANK , FLAG_SIGN};

const char *MODIFIERS[] = {"hh", "h", "ll", "l",
                            "j", "z", "t"};

const va_list_fct_t VA_LIST_MOD[] = {&va_list_nbchar, &va_list_nbshort,
                            &va_list_nblonglong, &va_list_nblong,
                            &va_list_nblonglong, &va_list_nbint,
                            &va_list_nbint};

const char SPECIFIERS[] = {'p',
                        'o', 'u',
                        'd', 'i',
                        'c',
                        's', 'S',
                        'b', 'x', 'X',
                        'f', 'F'};

const va_list_fct_t VA_LIST_SPEC[] = {&va_list_ptr,
                                NULL, NULL,
                                NULL, NULL,
                                &va_list_char,
                                &va_list_str, &va_list_str,
                                NULL, NULL, NULL,
                                &va_list_double, &va_list_double};

const print_fct_t PRINT_FCTS[] = {&print_ptr,
                                &print_octal, &print_unnb,
                                &print_nb, &print_nb,
                                &print_char,
                                &print_str, &print_fullstr,
                                &print_binary, &print_hexa, &print_uphexa,
                                &print_double, &print_double};

#endif /* !PRINTF_VALUES_H_ */