/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** Displays the content of an array of words
*/

#include "my.h"
#include <sys/stat.h>

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}

int my_show_word_array_rev(char *const *tab)
{
    for (int i = my_strlen_double(tab) - 1; i >= 0; i--) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}

void my_sort_time_array(char **tab, char *path)
{
    int len = my_strlen_double(tab);
    char *file1;
    char *file2;
    long time_file1 = 0;
    long time_file2 = 0;
    struct stat st;
    int j = 0;
    for (int i = 0; j < len - 1; i++) {
        file1 = new_file(path, tab[j]);
        file2 = new_file(path, tab[j + 1]);
        lstat(file1, &st);
        time_file1 = st.st_mtime;
        lstat(file2, &st);
        time_file2 = st.st_mtime;
        if (time_file2 > time_file1) {
            my_swap_char(&tab[j], &tab[j + 1]);
            j = 0;
        } else
            j++;
    }
}

int my_sort_alphabet_array(char **tab)
{
    int len = my_strlen_double(tab);
    int j = 0;
    for (int i = 0; j < len - 1; i++) {
        if (my_strcmp_ignore_case(tab[j], tab[j + 1]) == 1) {
            my_swap_char(&tab[j], &tab[j + 1]);
            j = 0;
        } else {
            j++;
        }
    }
    return 0;
}

char **my_sort_word_array_rev(char **tab)
{
    int j = my_strlen_double(tab)-1;
    for (int i = 0; i < middle_double(tab); i++) {
        my_swap_char(&tab[i], &tab[j]);
        j--;
    }
    return tab;
}
