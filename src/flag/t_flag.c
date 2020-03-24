/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** t_flag.c
*/

#include "my_ls.h"

int check_order(link_t *link)
{
    node_t *node = link->head;

    while (node->next != NULL) {
        if (node->info.st_mtimensec > node->next->info.st_mtimensec)
            return (84);
        node = node->next;
    }
    return (1);
}

void manage_t(link_t *link)
{
    node_t *node = link->head;

    while (node != NULL) {
        node = node->next;
    }
}