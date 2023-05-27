/*
** EPITECH PROJECT, 2022
** s_flag.c
** File description:
** Prints a character string (like %s).
** However, non-printable characters (ASCII value
** strictly smaller than 32 or greater or equal than 127)
** must be represented by a backslash to be followed by
** the character’s value in octal base.
*/

#include <stdlib.h>
#include "my.h"

int my_putnbr_base_s(unsigned int nbr, char *base, int count, char *array)
{
    int len = my_strlen(base);
    int reste = nbr % len;
    int quotient = nbr / len;
    if (quotient != 0) {
        count = my_putnbr_base_s(quotient, base, count, array);
    }
    array[count] = base[reste];
    count += 1;
    return count;
}

void reset_array(char *array)
{
    for (int i = 0; i < 5; i++)
        array[i] = '\0';
}

int s_flag(char *str)
{
    int count = 0;
    char *array = malloc(sizeof(char) * 5);
    reset_array(array);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            count += my_putchar('\\');
            count += my_putnbr_base_s(str[i], "01234567", 0, array);
            count = zero_before(array, count);
            my_putstr(array);
            reset_array(array);
        } else {
            count += my_putchar(str[i]);
        }
    }
    free(array);
    return count;
}

int s_flag_zero(char *str)
{
    int count = 0;
    char *array = malloc(sizeof(char) * 5);
    reset_array(array);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            count++;
            count += my_putnbr_base_s(str[i], "01234567", 0, array);
            count = zero_before_zero(array, count);
            reset_array(array);
        } else {
            count++;
        }
    }
    free(array);
    return count;
}
