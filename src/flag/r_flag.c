/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** r_flag.c
*/

#include "my_ls.h"

void r_file2(char **av, int ac, link_t *link, sheat_t *new_path)
{
    DIR *dir;
    file_t f;

    if (new_path->etat == 0) {
        new_path->path = fill_file(av, ac);
        new_path->path = my_strcat("./", new_path->path);
        dir = opendir(new_path->path);
        new_path->etat = 1;
    } else
        dir = opendir(new_path->path);
    while ((f.file = readdir(dir))) {
        if (f.file->d_name[0] == '.')
            continue;
        lstat(build_path(new_path->path, f.file->d_name), &f.info);
        add_node(f.file, link, build_path(new_path->path, f.file->d_name));
        if (S_ISDIR(f.info.st_mode)) {
            new_path->path = build_path(new_path->path, f.file->d_name);
            r_file2(av, ac, link, new_path);
        }
    }
}

sheat_t init_new_path(void)
{
    sheat_t new_path;

    new_path.etat = 0;
    return (new_path);
}

void manage_r(char **av, int ac, link_t *link, char *path)
{
    int nbr_file = number_file(av, ac);
    DIR *dir;
    sheat_t new_path = init_new_path();
    struct dirent *file;
    struct stat info;

    if (nbr_file == 0) {
        dir = opendir(path);
        while ((file = readdir(dir))) {
            if (file->d_name[0] == '.')
                continue;
            lstat(build_path(path, file->d_name), &info);
            add_node(file, link, build_path(path, file->d_name));
            if (S_ISDIR(info.st_mode)) {
                new_path.path = build_path(path, file->d_name);
                manage_r(av, ac, link, new_path.path);
            }
        }
    } else
        r_file2(av, ac, link, &new_path);
}