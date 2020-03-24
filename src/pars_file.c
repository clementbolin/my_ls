/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** pars_file.c
*/

#include "my_ls.h"

char *fill_file(char **av, int ac)
{
    char *folder = malloc(sizeof(char) * 250);

    for (int i = 1; i != ac; i++) {
        if (av[i][0] == '-')
            continue;
        for (int k = 0; av[i][k] != '\0'; k++) {
            folder[k] = av[i][k];
            if (av[i][k] == '\0')
                folder[k] = '\0';
        }
    }
    return (folder);
}