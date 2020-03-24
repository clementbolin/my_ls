/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** tool.c
*/

#include "my_ls.h"

int check_slash(char const *path)
{
    for (int i = 0; path[i] != '\0'; i++)
        if (path[i] == '/')
            return (1);
    return (0);
}

void recup_name_folder(char *path)
{
    int len = my_strlen(path) - 1;
    int i = 0;
    char *name;

    if (path[len] == '/') len -= 1;
    for (int tmp = len; path[tmp] != '/'; tmp--, i++);
    name = malloc(sizeof(char) * (i + 1));
    if (name == NULL) {
        putstr_error("ERROR: malloc recup_name_folder\n");
        exit (84);
    }
    i = 0;
    for (; path[len] != '/'; len--, i++)
        name[i] = path[len];
    name[i] = '\0';
    name = my_revstr(name);
    my_printf("%s", name);
}

int total_file(link_t *link)
{
    node_t *node = link->head;
    int total = 0;

    while (node != NULL) {
        total += node->info.st_blocks;
        node = node->next;
    }
    return (total/2);
}

int number_file(char **av, int ac)
{
    int number_file = 0;

    for (int i = 1; i != ac; i++) {
        if (av[i][0] == '-')
            continue;
        number_file += 1;
    }
    return (number_file);
}

char *build_path(char *str, char *name)
{
    size_t i = 0;
    size_t a = 0;
    size_t size = my_strlen(str) + my_strlen(name) + 2;
    char *str_return = malloc(sizeof(char)* size);

    while (str[i]) {
        str_return[i] = str[i];
        i++;
    }
    if (str_return[i - 1] != '/') {
        str_return[i] = '/';
        i++;
    }
    for (; name[a]; a++) {
        str_return[i] = name[a];
        i++;
    }
    str_return[i] = '\0';
    return (str_return);
}