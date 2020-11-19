/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf header
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>
#include "flags_printf.h"

typedef void *(*va_list_fct_t) (va_list *arg);
typedef int (*print_fct_t) (void *value, int flags, int fwidth, int precision);
typedef struct {
    va_list_fct_t length_modif;
    int flags;
    int field_width;
    int precision;
} info_printf_t;

int my_printf(char *str, ...);
int my_vprintf(char *str, va_list arg_list);
int printf_conversion(char **str, va_list *list, int *length);

void *va_list_nbchar(va_list *arg);
void *va_list_nbshort(va_list *arg);
void *va_list_nbint(va_list *arg);
void *va_list_nblong(va_list *arg);
void *va_list_nblonglong(va_list *arg);

void *va_list_char(va_list *arg);
void *va_list_str(va_list *arg);
void *va_list_ptr(va_list *arg);

void *va_list_double(va_list *arg);

int print_nb(void *value, int flags, int fwidth, int precision);
int print_unnb(void *value, int flags, int fwidth, int precision);
int print_octal(void *value, int flags, int fwidth, int precision);
int print_binary(void *value, int flags, int fwidth, int precision);
int print_hexa(void *value, int flags, int fwidth, int precision);
int print_uphexa(void *value, int flags, int fwidth, int precision);

int print_char(void *value, int flags, int fwidth, int precision);
int print_str(void *value, int flags, int fwidth, int precision);
int print_fullstr(void *value, int flags, int fwidth, int precision);
int print_ptr(void *value, int flags, int fwidth, int precision);

int print_double(void *value, int flags, int fwidth, int precision);

#endif /* !MY_PRINTF_H_ */