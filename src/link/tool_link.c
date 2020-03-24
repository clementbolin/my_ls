/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** tool_link.c
*/

#include "my_ls.h"

int len_link(link_t *link)
{
    int len = 0;
    node_t *node = link->head;

    while (node != NULL) {
        len += 1;
        node = node->next;
    }
    return (len);
}

void swap_node(node_t *node1, node_t *node2, link_t *link)
{
    node_t *tmp = node1->next;

    node1->next = node2->next;
    node1->next = tmp;
    if (node1 != link->head)
        link->head = node2;
}