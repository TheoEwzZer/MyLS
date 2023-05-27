/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"

int handling(int argc, char **argv, char **path_list, int multi)
{
    char *flag = generate_char_flag(argc, argv);
    int error = 0;
    int j = 0;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            path_list[j] = argv[i];
            j++;
        }
    }
    my_sort_alphabet_array(path_list);
    if (check_flag(flag, 'r'))
        my_sort_word_array_rev(path_list);
    for (int i = 0; i < my_strlen_double(path_list); i++) {
        if (my_ls(flag, path_list[i], multi) == 84)
            error = 84;
    }
    return error;
}

int main(int argc, char **argv)
{
    int multi = 0;
    char *flag = generate_char_flag(argc, argv);
    if (check_flag(flag, 'R'))
        multi = 1;
    char *path = ".";
    int path_nb = 0;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-')
            path_nb++;
    }
    char **path_list = malloc(sizeof(char *) * (path_nb + 1));
    path_list[path_nb] = '\0';
    if (path_nb >= 2)
        return handling(argc, argv, path_list, 1);
    if (path_nb == 1)
        return handling(argc, argv, path_list, multi);
    return my_ls(flag, path, multi);
}
