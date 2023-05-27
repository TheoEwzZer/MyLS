/*
** EPITECH PROJECT, 2022
** malloc_result.c
** File description:
** malloc_result
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

char **add_files_l(char **result, char *file_l, int i)
{
    int len = my_strlen(file_l);
    result[i] = malloc(sizeof(char) * (len + 1));
    for (int j = 0; j <= len; j++)
        result[i][j] = '\0';
    my_strcpy(result[i], file_l);
    return result;
}

char **total_files(char *flag, char *path)
{
    int total = 0;
    struct dirent *file;
    DIR *current_dir;
    if ((current_dir = opendir(path)) == NULL)
        return 0;
    while ((file = readdir(current_dir)) != NULL) {
        if (my_strncmp(file->d_name, ".", 1) == 0 && !check_flag(flag, 'a'))
            continue;
        total += 1;
    }
    char **result = malloc(sizeof(char *) * (total + 1));
    result[total] = '\0';
    return result;
}

char **add_files(char **result, struct dirent *file, int i)
{
    int len = my_strlen(file->d_name);
    result[i] = malloc(sizeof(char) * (len + 1));
    for (int j = 0; j <= len; j++)
        result[i][j] = '\0';
    my_strcpy(result[i], file->d_name);
    return result;
}

char *l_flag_link(char *result, char* file3, struct stat st)
{
    char *linkname = malloc(st.st_size + 1);
    if (linkname == NULL) {
        return result;
    }
    int r = readlink(file3, linkname, st.st_size + 1);
    if (r < 0 || r > st.st_size) {
        return result;
    }
    linkname[st.st_size] = '\0';
    my_strcat(result, " -> ");
    my_strcat(result, linkname);
    return result;
}

int l_flag_len_link(char* file, struct stat st)
{
    int len = 0;
    char *linkname = malloc(st.st_size + 1);
    if (linkname == NULL) {
        return len;
    }
    int r = readlink(file, linkname, st.st_size + 1);
    if (r < 0 || r > st.st_size) {
        return len;
    }
    linkname[st.st_size] = '\0';
    len += my_strlen(linkname) + 4;
    return len;
}
