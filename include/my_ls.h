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

#define SORT_MASK 46

#define major(dev) ((int)(((unsigned int) (dev) >> 8) & 0xff))
#define minor(dev) ((int)((dev) & 0xff))

typedef struct {
    char *name;
    unsigned char type;
    struct stat *statbuf;
} file_t;

typedef struct {
    unsigned char is_file;
    char *path;
    list_t *files;
} folder_t;

typedef void (*print_folder_t)(folder_t *folder);

int get_flags(int ac, char *av[]);
int read_folders(int ac, char *av[], list_t **folders, int flags);
int read_folder_content(char *path, list_t **folders, int flags);
void sort_files(list_t *folders, int flags);
void print_folders(list_t *folders, int n_folders, int flags);
void print_type_and_permission(file_t *file);
void print_total_blocks(list_t *files);
void print_color(file_t *file);

void add_file_to_list(char *filepath, struct dirent *fileinfo, list_t **list);
void add_folder_to_list(char *path, list_t *files, list_t **folders,
unsigned char is_file);
void delete_folders(list_t *folders);

#endif /* !MY_LS_H_ */