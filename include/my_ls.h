/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_ls
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "my_list.h"

#define FLAG_ALL 1
#define FLAG_LIST 2
#define FLAG_RECURSIVE 4
#define FLAG_DIR 8
#define FLAG_REVERSE 16
#define FLAG_TIME 32

typedef struct {
    struct dirent *file;
    struct stat *statbuf;
} file_t;

typedef struct {
    char *path;
    list_t *files;
} folder_t;

typedef void (*print_folder_t)(list_t *files);

int get_flags(int ac, char *av[]);
int read_folders(int ac, char *av[], list_t **folders, int flags);
int read_folder_content(char *path, list_t **folders, int flags);
void print_folders(list_t *folders, int n_folders, int flags);

#endif /* !MY_LS_H_ */