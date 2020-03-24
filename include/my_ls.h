/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** include
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include "struct.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

/* ############################ MY_LS #######################*/
void display_folder(char const *path, link_t *link);
void my_ls(int ac, char **av);
void display_res(link_t *link, char const *flag);

/* ########################### Flag ########################*/
void display_current(char **av, int ac, link_t *link);
void display_law_file(struct stat info);
void display_user(struct stat info);
void current_l(link_t *link, char **av, int ac);
void l_flag(node_t *node);
void a_flag(char const *path, link_t *link);

/* ########################## ERROR ########################*/
int error(char **av, int ac);
int valid_file(char const *path);

/* ######################### TOOL ##########################*/
void recup_name_folder(char *path);
int check_slash(char const *path);
int total_file(link_t *link);
int number_file(char **av, int ac);
char *build_path(char *path, char *name);
char *fill_file(char **av, int ac);

/* ######################### MANGE  #######################*/
char *manage_flag(char **av, int ac);
void manage_a(char **av, int ac, link_t *link);
void manage_r(char **av, int ac, link_t *link, char *path);
void send_function(char **av, char const *flag, int ac, link_t *link);

/* ######################## LINK ###########################*/
link_t *init_link(void);
node_t *create_node(struct dirent *rep, char const *path);
void add_node(struct dirent *rep, link_t *link, char const *path);
void delete_node(int size, link_t *link);
int len_link(link_t *link);
void swap_node(node_t *node1, node_t *node2, link_t *link);

#endif /* !MY_LS_H_ */
