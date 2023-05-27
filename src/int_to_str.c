/*
** EPITECH PROJECT, 2022
** int_to_str.c
** File description:
** int_to_str
*/

#include <sys/stat.h>
#include "my.h"

int int_to_str(long nbr, int count, char *str)
{
    if (nbr < 0) {
        str[count] = '-';
        count++;
        count = int_to_str(-nbr, count, str);
    } else {
        int rest = nbr % 10;
        int quotient = nbr / 10;
        if (quotient != 0) {
            count = int_to_str(quotient, count, str);
        }
        str[count] = rest + 48;
        count++;
    }
    return count;
}

int is_directory(const char *path)
{
    struct stat st;
    int len = my_strlen(path);
    stat(path, &st);
    if (path[len - 1] == '.')
        return 0;
    return S_ISDIR(st.st_mode);
}

int is_existing(const char *path)
{
    struct stat st;
    stat(path, &st);
    if (S_ISBLK(st.st_mode))
        return 1;
    if (S_ISCHR(st.st_mode))
        return 1;
    if (S_ISDIR(st.st_mode))
        return 1;
    if (S_ISFIFO(st.st_mode))
        return 1;
    if (S_ISLNK(st.st_mode))
        return 1;
    if (S_ISREG(st.st_mode))
        return 1;
    if (S_ISSOCK(st.st_mode))
        return 1;
    return 0;
}
