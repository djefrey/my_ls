/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** colors_list
*/

#ifndef COLORS_LIST_H_
#define COLORS_LIST_H_

#include <sys/types.h>

#define NUMBER_COLORS 6

#define EXEC_COLOR "\e[1m\e[32m"
#define ARCHIVE_COLOR "\e[1m\e[31m"

const char* COLORS[] = {"\e[1m\e[34m", "\e[1m\e[36m",
                    "\e[1m\e[33m", "\e[1m\e[35m"};

const int COLORS_TYPE[] = {S_IFDIR, S_IFLNK,
                        S_IFBLK, S_IFSOCK};

#endif /* !COLORS_LIST_H_ */