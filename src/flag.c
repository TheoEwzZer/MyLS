/*
** EPITECH PROJECT, 2022
** flag.c
** File description:
** flag
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat2(char *dest, const char *src)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    for (int i = 1; i <= len_src; i++) {
        dest[len_dest + i - 1] = src[i];
    }
    return dest;
}

int check_flag(char *flag, char c)
{
    for (int i = 0; i < my_strlen(flag); i++) {
        if (flag[i] == c)
            return 1;
    }
    return 0;
}

char *generate_char_flag(int argc, char **argv)
{
    int sum = 0;
    for (int i = 0; i < argc; i++)
        sum += my_strlen(argv[i]);
    char *flag = malloc(sizeof(char) * (sum));
    for (int i = 0; i < sum; i++)
        flag[i] = '\0';
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-') {
            my_strcat2(flag, argv[i]);
        }
    }
    return flag;
}
