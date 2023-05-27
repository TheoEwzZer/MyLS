/*
** EPITECH PROJECT, 2022
** my_lst.c
** File description:
** my_ls
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

char *check_path(int argc, char **argv)
{
    char *path = ".";
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            path = argv[i];
            break;
        }
    }
    return path;
}

int check_multi(int multi, int is_first_path, char *path)
{
    if (multi) {
        if (is_first_path) {
            my_printf("\n");
        }
        my_printf("%s:\n", path);
        is_first_path = 1;
    }
    return is_first_path;
}

void print_ls_manage(char *flag, char **result, char *path, char **result_l)
{
    if (!check_flag(flag, 'l'))
        my_sort_alphabet_array(result);
    else
        my_sort_alphabet_array_l(result_l, result);
    if (check_flag(flag, 't')) {
        if (check_flag(flag, 'l'))
            my_sort_time_array_l(result_l, result, path);
        else
            my_sort_time_array(result, path);
    }
    if (check_flag(flag, 'r'))
        my_show_word_array_rev(result);
    else
        my_show_word_array(result);
}

int print_ls(DIR *current_dir, char *flag, char *path)
{
    char **result = total_files(flag, path);
    char **result_l = total_files(flag, path);
    struct dirent *file;
    for (int i = 0; (file = readdir(current_dir)) != NULL;) {
        if (my_strncmp(file->d_name, ".", 1) == 0 && !check_flag(flag, 'a'))
            continue;
        if (check_flag(flag, 'l'))
            result = add_files_l(result, l_flag(file, path), i);
        else
            result = add_files(result, file, i);
        result_l = add_files(result_l, file, i);
        i++;
    }
    print_ls_manage(flag, result, path, result_l);
    if (check_flag(flag, 'R'))
        flag_upperr(flag, result, result_l, path);
    closedir(current_dir);
    free(result);
    return 0;
}

int my_ls(char *flag, char *path, int multi)
{
    static int is_first_path2 = 0;
    static int is_first_path = 0;
    DIR *current_dir;
    if (check_flag(flag, 'd'))
        return flag_d(path, flag);
    if ((current_dir = opendir(path)) == NULL) {
        if (errno != ENOTDIR) {
            write(2, "my_ls: cannot access '", 22);
            write(2, path, my_strlen(path)), perror("'");
            closedir(current_dir);
            return 84;
        }
        is_first_path2 = 1;
        return specific(path, flag);
    }
    first_path2(is_first_path2);
    is_first_path = check_multi(multi, is_first_path, path);
    if (check_flag(flag, 'l'))
        total_l(flag, path);
    return print_ls(current_dir, flag, path);
}
