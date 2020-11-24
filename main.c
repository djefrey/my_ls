/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** main
*/

#include <stdlib.h>
#include "my_ls.h"
#include "my_list.h"

int main(int ac, char *av[])
{
    int flags = get_flags(ac, av);
    list_t *folders = NULL;
    int n_folders = read_folders(ac, av, &folders, flags);

    if (n_folders == 0)
        n_folders = read_folder_content(".", &folders, flags);
    sort_files(folders, flags);
    print_folders(folders, n_folders, flags);
    delete_folders(folders);
    return (0);
}