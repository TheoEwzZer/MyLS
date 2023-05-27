/*
** EPITECH PROJECT, 2022
** upperr_flag.c
** File description:
** upperr_flag
*/

#include "my.h"

void flag_upperr(char *flag, char **result, char **result_l, char *path)
{
    if (check_flag(flag, 'l')) {
        for (int i = 0; result_l[i]; i++) {
            char *file2 = new_file(path, result_l[i]);
            is_directory(file2) ? my_ls(flag, file2, 1) : 0;
        }
    } else {
        for (int i = 0; result[i]; i++) {
            char *file2 = new_file(path, result[i]);
            is_directory(file2) ? my_ls(flag, file2, 1) : 0;
        }
    }
}
