/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** link.c
*/

#include "my_ls.h"

link_t *init_link(void)
{
    link_t *link = malloc(sizeof(*link));

    if (!link) {
        putstr_error("ERROR: malloc init link\n");
        return (NULL);
    }
    link->head = NULL;
    return (link);
}

node_t *create_node(struct dirent *rep, char const *path)
{
    node_t *node = malloc(sizeof(*node));

    if (!node) {
        putstr_error("ERROR: malloc node fail\n");
        return (NULL);
    }
    node->file = rep;
    node->father = path;
    lstat(path, &node->info);
    node->next = NULL;
    return (node);
}

void add_node(struct dirent *rep, link_t *link, char const *path)
{
    node_t *current = NULL;

    if (link->head == NULL)
        link->head = create_node(rep, path);
    else {
        current = link->head;
        while (current->next != NULL)
            current = current->next;
        current->next = create_node(rep, path);

    }
}

void delete_node(int size, link_t *link)
{
    node_t *current = link->head;
    node_t *prev = current;
    int i = 0;

    while (current != NULL) {
        if (i == size) {
            prev->next = current->next;
            if (current == link->head)
                link->head = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
        i += 1;
    }
}