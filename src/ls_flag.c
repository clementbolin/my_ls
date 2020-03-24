/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** ls_flag.c
*/

#include "my.h"
#include "my_ls.h"

static function_t array_flag[] = {
    {'a', manage_a},
    {'\0', display_current},
};

void fill_flag(char *flag, char *av)
{
    int len = my_strlen(flag);

    for (int i = 1; av[i] != '\0'; i++, len++) {
        flag[len] = av[i];
    }
    flag[len] = '\0';
}

char *manage_flag(char **av, int ac)
{
    char *flag = malloc(sizeof(char) * (5 + 1));

    flag[0] = '\0';
    for (int i = 1; i != ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][0] == '-') {
                fill_flag(flag, av[i]);
                break;
            }
        }
    }
    return (flag);
}

void send_function(char **av, char const *flag, int ac, link_t *link)
{
    int etat = 0;

    for (int i = 0; flag[i]; i++) {
        if (flag[i] == 'R') {
            manage_r(av, ac, link, "./");
            etat = 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; flag[j]; j++) {
            if (flag[j] == array_flag[i].c) {
                array_flag[i].ft(av, ac, link);
                etat = 1;
            }
        }
    }
    if (flag[0] == '\0')
        display_current(av, ac, link);
    if (flag[0] == 'l' && etat == 0)
        current_l(link, av, ac);
}