/*
** EPITECH PROJECT, 2022
** width.c
** File description:
** width.c
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

int get_width(var_t var, const char *format, char *array)
{
    for (int i = 0; i < my_strlen(format) + 1; i++)
        array[i] = '\0';
    int k = 0;
    for (int i = var.j + 1; format[i] >= 48 && format[i] <= 57; i++) {
        array[k] = format[i];
        k++;
        var.j++;
    }
    return var.j;
}
