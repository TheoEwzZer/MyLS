/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** Copies n characters from a string into another. The destination string
** will already have enough memory to contain n characters.
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = my_strlen(src);
    for (int i = 0; i <= len && i < n; i++) {
        dest[i] = src[i];
    }
    return dest;
}
