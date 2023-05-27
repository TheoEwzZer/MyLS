/*
** EPITECH PROJECT, 2022
** permission.c
** File description:
** permission
*/

#include <sys/stat.h>
#include "my.h"

void owner(char* file, char *rwx)
{
    struct stat st;
    lstat(file, &st);
    if (st.st_mode & S_IRUSR)
        my_strcat(rwx, "r");
    else
        my_strcat(rwx, "-");
    if (st.st_mode & S_IWUSR)
        my_strcat(rwx, "w");
    else
        my_strcat(rwx, "-");
    if (st.st_mode & S_IXUSR)
        my_strcat(rwx, "x");
    else if (st.st_mode & S_ISUID)
        my_strcat(rwx, "S");
    else
        my_strcat(rwx, "-");
}

void group(char* file, char *rwx)
{
    struct stat st;
    lstat(file, &st);
    if (st.st_mode & S_IRGRP)
        my_strcat(rwx, "r");
    else
        my_strcat(rwx, "-");
    if (st.st_mode & S_IWGRP)
        my_strcat(rwx, "w");
    else
        my_strcat(rwx, "-");
    if (st.st_mode & S_IXGRP)
        my_strcat(rwx, "x");
    else if (st.st_mode & S_ISGID)
        my_strcat(rwx, "S");
    else
        my_strcat(rwx, "-");
}

void other(char* file, char *rwx)
{
    struct stat st;
    lstat(file, &st);
    if (st.st_mode & S_IROTH)
        my_strcat(rwx, "r");
    else
        my_strcat(rwx, "-");
    if (st.st_mode & S_IWOTH)
        my_strcat(rwx, "w");
    else
        my_strcat(rwx, "-");
    if (st.st_mode & S_IXOTH)
        my_strcat(rwx, "x");
    else if (st.st_mode & S_ISVTX)
        my_strcat(rwx, "T");
    else
        my_strcat(rwx, "-");
}
