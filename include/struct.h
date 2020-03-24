/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

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

typedef struct node_s {
    struct dirent *file;
    struct stat info;
    char const *father;
    struct node_s *next;
} node_t;

typedef struct link_s {
    node_t *head;
} link_t;

typedef struct function_s {
    char c;
    void (*ft)(char **, int, link_t *);
} function_t;

typedef struct sheat_s {
    char *path;
    int etat;
} sheat_t;

typedef struct file_s {
    struct dirent *file;
    struct stat info;
} file_t;

#endif /* !STRUCT_H_ */