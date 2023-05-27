/*
** EPITECH PROJECT, 2022
** l_flag_only.c
** File description:
** l_flag_only
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *l_flag2_only(char *result3, char* file)
{
    struct stat st;
    char *file3 = my_strdup(file);
    lstat(file, &st);
    add_perm(file3, result3);
    my_strcat(result3, " ");
    add_number(st.st_nlink, result3);
    my_strcat(result3, " ");
    add_owner_group(result3, st.st_uid, st.st_gid);
    my_strcat(result3, " ");
    add_number(st.st_size, result3);
    my_strcat(result3, " ");
    add_time(result3, &st.st_mtime);
    my_strcat(result3, " ");
    my_strcat(result3, file);
    if (S_ISLNK(st.st_mode)) {
        l_flag_link(result3, file3, st);
    }
    return result3;
}

char *l_flag_only(char *file)
{
    int len = my_strlen(file);
    len += l_flag_len(file);
    char *result3 = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i <= len; i++) {
        result3[i] = '\0';
    }
    return l_flag2_only(result3, file);
}
