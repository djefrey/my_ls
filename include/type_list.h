/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** type_list
*/

#ifndef TYPE_LIST_H_
#define TYPE_LIST_H_

#define NUMBER_TYPE 7

const int TYPE_LS[] = {S_IFREG, S_IFDIR, S_IFLNK,
                    S_IFIFO, S_IFSOCK, S_IFBLK, S_IFCHR};

const char TYPE_LS_VALUE[] = {'-', 'd', 'l',
                    'p', 's', 'b', 'c'};


#endif /* !TYPE_LIST_H_ */