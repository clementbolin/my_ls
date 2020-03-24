/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** l_flag.c
*/

#include "my.h"
#include "my_ls.h"

void l_flag_file(link_t *link, char **av, int ac)
{
    char *path = fill_file(av, ac);
    struct dirent *rep;
    DIR *dir;

    path = my_strcat("./", path);
    dir = opendir(path);
    while ((rep = readdir(dir))) {
        if (rep->d_name[0] == '.')
            continue;
        add_node(rep, link, build_path(path, rep->d_name));
    }
}

void current_l(link_t *link, char **av, int ac)
{
    int nbr_file = number_file(av, ac);
    DIR *dir = opendir(".");
    struct dirent *rep = NULL;

    if (nbr_file == 0) {
        if (!dir) {
            perror("");
            exit(84);
        }
        while ((rep = readdir(dir))) {
            if (rep == NULL) {
                perror("");
                exit(84);
            }
            if (rep->d_name[0] == '.')
                continue;
            add_node(rep, link, rep->d_name);
        }
    } else
        l_flag_file(link, av, ac);
}

void display_law_file(struct stat info)
{
    if (S_ISDIR(info.st_mode))
        my_putchar('d');
    else
        my_putchar('-');
    (info.st_mode & S_IRUSR) ? my_putchar('r') : my_putchar('-');
    (info.st_mode & S_IWUSR) ? my_putchar('w') : my_putchar('-');
    (info.st_mode & S_IXUSR) ? my_putchar('x') : my_putchar('-');
    (info.st_mode & S_IRGRP) ? my_putchar('r') : my_putchar('-');
    (info.st_mode & S_IWGRP) ? my_putchar('w') : my_putchar('-');
    (info.st_mode & S_IXGRP) ? my_putchar('x') : my_putchar('-');
    (info.st_mode & S_IROTH) ? my_putchar('r') : my_putchar('-');
    (info.st_mode & S_IWOTH) ? my_putchar('w') : my_putchar('-');
    (info.st_mode & S_IXOTH) ? my_putchar('x') : my_putchar('-');
}

void display_user(struct stat info)
{
    struct passwd *p;
    struct group *grp;

    p = getpwuid(info.st_uid);
    grp = getgrgid(info.st_uid);
    my_printf(" %s %s", p->pw_name, grp->gr_name);
}

void l_flag(node_t *node)
{
    display_law_file(node->info);
    my_printf(" %d", node->info.st_nlink);
    display_user(node->info);
    my_printf(" %d ", node->info.st_size);
    write(1, (ctime(&node->info.st_mtime) + 4), \
    my_strlen(ctime(&node->info.st_mtime)) - 13);
    if (check_slash(node->file->d_name) == 1) {
        my_putchar(' ');
        recup_name_folder(node->file->d_name);
        my_putchar('\n');
    }
    else
    my_printf(" %s\n", node->file->d_name);
}