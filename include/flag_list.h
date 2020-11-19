/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** flag_list
*/

#ifndef FLAG_LIST_H_
#define FLAG_LIST_H_

#include "my_ls.h"

#define NUMBER_FLAGS 6

const char FLAGS_LS[] = {'a', 'l', 'R',
                    'd', 'r', 't'};

const int FLAGS_LS_VALUE[] = {FLAG_ALL, FLAG_LIST, FLAG_RECURSIVE,
                        FLAG_DIR, FLAG_REVERSE, FLAG_TIME};

#endif /* !FLAG_LIST_H_ */