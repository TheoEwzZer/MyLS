/*
** EPITECH PROJECT, 2022
** flag_suite.c
** File description:
** flag_suite
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

void flag4_2(var_t var, const char *format, va_list ap, int *result)
{
    if (format[var.j + 1] == 'f' || format[var.j + 1] == 'e'
    || format[var.j + 1] == 'E') {
        if (var.hashtag) {
            specifier_hashtag_point(var, format, ap, result);
        } else {
            specifier_point(var, format, ap, result);
        }
    } else {
        specifier(var, format, ap, result);
    }
}

int flag6(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'l':
        var.j++;
        while (format[var.j + 1] == ' ' || format[var.j + 1] == 'l')
            var.j++;
        var.j = specifier_long(var, format, ap, result);
        break;
    default:
        var.j = specifier(var, format, ap, result);
    }
    return var.j;
}
