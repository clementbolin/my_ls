/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls.c
*/

#include "my_ls.h"
#include "my.h"

void display_folder(char const *path, link_t *link)
{
    struct dirent *folder;
    DIR *rep = opendir(path);

    while ((folder = readdir(rep))) {
        if (folder->d_name[0] == '.')
            continue;
        add_node(folder, link, path);
    }
}

void display_current(char **av, int ac, link_t *link)
{
    int nbr_file = number_file(av, ac);
    char *path = fill_file(av, ac);

    path = my_strcat("./", path);
    if (nbr_file != 0) {
        display_folder(path, link);
    }
}

void display_res(link_t *link, char const *flag)
{
    node_t *node = link->head;
    int etat = 0;
    int total = total_file(link);

    for (int i = 0; flag[i] != '\0'; i++) {
        if (flag[i] == 'l')
            etat = 1;
    }
    if (etat == 1) {
        my_printf("total %d\n", total);
        while (node != NULL) {
            l_flag(node);
            node = node->next;
        }
    } else {
        while (node != NULL) {
            my_printf("%s\n", node->file->d_name);
            node = node->next;
        }
    }
}

void my_ls(int ac, char **av)
{
    char *flag = manage_flag(av, ac);
    link_t *data_file = init_link();

    if (ac < 2)
        display_folder(".", data_file);
    send_function(av, flag, ac, data_file);
    display_res(data_file, flag);
}