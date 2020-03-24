/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** error.c
*/

#include "my_ls.h"
#include "my.h"

int check_nb_flag(char **av, int ac)
{
    for (int i = 1; i != ac; i++) {
        if (av[i][0] == '-')
            return (84);
    }
    return (0);
}

int valid_file(char const *path)
{
    struct stat info;
    int etat = 0;

    etat = stat(path, &info);
    if (etat < 0)
        exit (84);
    return (0);
}

int error(char **av, int ac)
{
    char *file = fill_file(av, ac);
    int nb_file = number_file(av, ac);

    if (nb_file == 0)
        return (0);
    valid_file(file);
    return (0);
}