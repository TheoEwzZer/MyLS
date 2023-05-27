/*
** EPITECH PROJECT, 2022
** l_flag_print.c
** File description:
** l_flag_print
*/

#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include "my.h"

void add_perm(char *file, char *result)
{
    char *rwx = malloc(sizeof(char) * 11);
    for (int i = 0; i <= 10; i++)
        rwx[i] = '\0';
    type(file, rwx);
    owner(file, rwx);
    group(file, rwx);
    other(file, rwx);
    free(file);
    my_strcat(result, rwx);
    free(rwx);
}

void add_number(int number, char *result)
{
    char *strnumber = malloc(sizeof(char) * (my_put_nbr_count(number, 0) + 1));
    for (int i = 0; i <= my_put_nbr_count(number, 0); i++) {
        strnumber[i] = '\0';
    }
    int_to_str(number, 0, strnumber);
    my_strcat(result, strnumber);
    free(strnumber);
}

void add_time(char *result, const time_t *timer)
{
    char *time = ctime(timer);
    time += 4;
    for (int i = 0; i < 12; i++) {
        if (time[0] == ' ' && time[1] == ' ') {
            time++;
            i++;
        }
        my_strncat(result, time, 1);
        time++;
    }
}

void add_owner_group(char *result, uid_t uid, gid_t gid)
{
    struct passwd *pw;
    struct group *gr;
    if ((pw = getpwuid(uid)) != NULL) {
        my_strcat(result, pw->pw_name);
    } else {
        add_number(uid, result);
    }
    my_strcat(result, " ");
    if ((gr = getgrgid(gid)) != NULL) {
        my_strcat(result, gr->gr_name);
    } else {
        add_number(gid, result);
    }
}

int l_flag_len(char* file)
{
    int len = 29;
    struct stat st;
    struct passwd *pw;
    struct group *gr;
    lstat(file, &st);
    len += my_put_nbr_count(st.st_nlink, 0);
    if ((pw = getpwuid(st.st_uid)) != NULL)
        len += my_strlen(pw->pw_name);
    else
        len += my_put_nbr_count(st.st_uid, 0);
    if ((gr = getgrgid(st.st_gid)) != NULL)
        len += my_strlen(gr->gr_name);
    else
        len += my_put_nbr_count(st.st_gid, 0);
    len += my_put_nbr_count(st.st_size, 0);
    if (S_ISLNK(st.st_mode)) {
        len += l_flag_len_link(file, st);
    }
    return len;
}
