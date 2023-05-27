/*
** EPITECH PROJECT, 2022
** l_flag3.c
** File description:
** l_flag3
*/

#include <sys/stat.h>
#include "my.h"

void my_sort_time_array_l(char **tab, char **tab2, char *path)
{
    char *file1;
    char *file2;
    long time_file1 = 0;
    struct stat st;
    int j = 0;
    for (int i = 0; j < my_strlen_double(tab) - 1; i++) {
        file1 = new_file(path, tab[j]);
        file2 = new_file(path, tab[j + 1]);
        lstat(file1, &st);
        time_file1 = st.st_mtime;
        lstat(file2, &st);
        if (st.st_mtime > time_file1) {
            my_swap_char(&tab[j], &tab[j + 1]);
            my_swap_char(&tab2[j], &tab2[j + 1]);
            j = 0;
        } else {
            j++;
        }
    }
}

int my_sort_alphabet_array_l(char **tab, char **tab2)
{
    int len = my_strlen_double(tab);
    int j = 0;
    for (int i = 0; j < len - 1; i++) {
        if (my_strcmp_ignore_case(tab[j], tab[j + 1]) == 1) {
            my_swap_char(&tab[j], &tab[j + 1]);
            my_swap_char(&tab2[j], &tab2[j + 1]);
            j = 0;
        } else {
            j++;
        }
    }
    return 0;
}

int first_path2(int is_first_path2)
{
    if (is_first_path2) {
        my_putchar('\n');
        is_first_path2 = 0;
    }
    return is_first_path2;
}
