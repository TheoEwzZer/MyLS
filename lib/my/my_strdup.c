/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** Allocates memory and copies the string given as argument in it.
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i <= len; i++)
        str[i] = '\0';
    my_strcpy(str, src);
    return str;
}

char **my_strdup_double(char **src)
{
    int len = my_strlen_double(src);
    int len2;
    char **str = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; i <= len; i++)
        str[i] = '\0';
    for (int i = 0; i < len; i++) {
        len2 = my_strlen(src[i]);
        str[i] = malloc(sizeof(char) * (len2 + 1));
        for (int j = 0; j <= len2; j++)
            str[i][j] = '\0';
        my_strcpy(str[i], src[i]);
    }
    return str;
}
