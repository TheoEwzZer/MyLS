/*
** EPITECH PROJECT, 2022
** l_flag.c
** File description:
** l_flag
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *new_file(char *path, char *file)
{
    int size = my_strlen(path) + 2 + my_strlen(file);
    char* file2 = malloc(sizeof(char) * size);
    for (int i = 0; i < size; i++)
        file2[i] = '\0';
    file2 = my_strcpy(file2, path);
    file2 = my_strcat(file2, "/");
    file2 = my_strcat(file2, file);
    return file2;
}

int total_l(char *flag, char *path)
{
    struct stat st;
    struct dirent *file;
    DIR *current_dir;
    if ((current_dir = opendir(path)) == NULL)
        return 0;
    int total = 0;
    while ((file = readdir(current_dir)) != NULL) {
        if (my_strncmp(file->d_name, ".", 1) == 0 && !check_flag(flag, 'a'))
            continue;
        char *file2 = new_file(path, file->d_name);
        stat(file2, &st);
        total += (st.st_blocks / 2);
    }
    my_printf("total %d\n", total);
    return 0;
}

void type(char* file, char *rwx)
{
    struct stat st;
    lstat(file, &st);
    if (S_ISREG(st.st_mode))
        rwx[0] = '-';
    if (S_ISDIR(st.st_mode))
        rwx[0] = 'd';
    if (S_ISLNK(st.st_mode))
        rwx[0] = 'l';
    if (S_ISBLK(st.st_mode))
        rwx[0] = 'b';
    if (S_ISCHR(st.st_mode))
        rwx[0] = 'c';
    if (S_ISFIFO(st.st_mode))
        rwx[0] = 'p';
    if (S_ISSOCK(st.st_mode))
        rwx[0] = 's';
}

char *l_flag2(char *result, struct dirent *dirent, char* file2)
{
    struct stat st;
    char *file3 = my_strdup(file2);
    lstat(file2, &st);
    add_perm(file2, result);
    my_strcat(result, " ");
    add_number(st.st_nlink, result);
    my_strcat(result, " ");
    add_owner_group(result, st.st_uid, st.st_gid);
    my_strcat(result, " ");
    add_number(st.st_size, result);
    my_strcat(result, " ");
    add_time(result, &st.st_mtime);
    my_strcat(result, " ");
    my_strcat(result, dirent->d_name);
    if (S_ISLNK(st.st_mode)) {
        l_flag_link(result, file3, st);
    }
    return result;
}

char *l_flag(struct dirent *dirent, char* file)
{
    char *file2 = new_file(file, dirent->d_name);
    int len = my_strlen(dirent->d_name);
    len += l_flag_len(file2);
    char *result = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i <= len; i++) {
        result[i] = '\0';
    }
    return l_flag2(result, dirent, file2);
}
