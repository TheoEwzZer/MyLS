/*
** EPITECH PROJECT, 2022
** d_flag.c
** File description:
** d_flag
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include <errno.h>

int flag_d(char *path, char *flag)
{
    if (my_strcmp(path, ".") == 0 || is_existing(path)) {
        if (errno) {
            write(2, "my_ls: cannot access '", 22);
            write(2, path, my_strlen(path));
            perror("'");
            return 84;
        }
        specific(path, flag);
        return 0;
    }
    write(2, "my_ls: cannot access '", 22);
    write(2, path, my_strlen(path));
    perror("'");
    return 84;
}

int specific(char *path, char *flag)
{
    if (my_strcmp(path, ".") == 0 || is_existing(path)) {
        char **result = malloc(sizeof(char *) * 2);
        result[1] = '\0';
        char **result_l = malloc(sizeof(char *) * 1);
        result_l[0] = '\0';
        if (my_strcmp(path, ".") == 0 && !check_flag(flag, 'a')
        && !check_flag(flag, 'd')) {
            return 0;
        }
        if (check_flag(flag, 'l'))
            result = add_files_l(result, l_flag_only(path), 0);
        else
            result = add_files_l(result, path, 0);
        print_ls_manage(flag, result, path, result_l);
        return 0;
    }
    write(2, "my_ls: cannot access '", 22);
    write(2, path, my_strlen(path));
    perror("'");
    return 84;
}
