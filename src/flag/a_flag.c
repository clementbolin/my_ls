/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** a_flag.c
*/

#include "my.h"
#include "my_ls.h"

void manage_a(char **av, int ac, link_t *link)
{
    if (ac > 3) {
        for (int i = 2; i != ac; i++) {
            if (check_slash(av[i]) == 1) {
                recup_name_folder(av[i]);
                my_printf(":\n");
            }
            else
                my_printf("%s:\n", av[i]);
            a_flag(av[i], link);
            if (i == ac-1)
                break;
            my_printf("\n");
        }
    } else
        a_flag(".", link);
}

void a_flag(char const *path, link_t *link)
{
    struct dirent *file;
    DIR *rep = opendir(path);

    if (!rep) {
        perror("");
        exit(84);
    }
    while ((file = readdir(rep)) != NULL) {
        if (file == NULL)
            break;
        add_node(file, link, file->d_name);
    }
}