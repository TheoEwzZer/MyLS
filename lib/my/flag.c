/*
** EPITECH PROJECT, 2022
** flag.c
** File description:
** flags
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

int flag5(var_t var, const char *format, va_list ap, int *result)
{
    char *array = malloc(sizeof(char) * (my_strlen(format) + 1));
    if (format[var.j + 1] == '#') {
        var.j++;
        while (format[var.j + 1] == ' ' || format[var.j + 1] == '#')
            var.j++;
        if (my_char_isnum(format[var.j + 1])) {
            var.j = get_width(var, format, array);
            var.width = my_getnbr(array);
            var.hashtag = 1;
            var.j = flag4(var, format, ap, result);
        } else
            var.j = specifier_hashtag(var, format, ap, result);
    } else if (my_char_isnum(format[var.j + 1])) {
        var.j = get_width(var, format, array);
        var.width = my_getnbr(array);
        var.j = specifier_nbr(var, format, ap, result);
    } else
        var.j = flag6(var, format, ap, result);
    free(array);
    return var.j;
}

int flag4(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case '.': var.j++;
        while (format[var.j + 1] == ' ' || format[var.j + 1] == '.')
            var.j++;
        if (my_char_isnum(format[var.j + 1])) {
            char *array = malloc(sizeof(char) * (my_strlen(format) + 1));
            var.j = get_width(var, format, array);
            var.width = my_getnbr(array);
            free(array);
            if (var.hashtag)
                specifier_hashtag_point(var, format, ap, result);
            else
                specifier_point(var, format, ap, result);
        } else {
            flag4_2(var, format, ap, result);
        } break;
    default:
        var.j = flag5(var, format, ap, result);
    }
    return var.j;
}

int flag3(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case '0':
        var.j++;
        while (format[var.j + 1] == ' ' || format[var.j + 1] == '0')
            var.j++;
        if (my_char_isnum(format[var.j + 1])) {
            char *array = malloc(sizeof(char) * (my_strlen(format) + 1));
            var.j = get_width(var, format, array);
            var.width = my_getnbr(array);
            free(array);
            specifier_zero(var, format, ap, result);
        } else if (format[var.j + 1] == '.')
            var.j = flag4(var, format, ap, result);
        else
            specifier(var, format, ap, result);
        break;
    default:
        var.j = flag4(var, format, ap, result);
    }
    return var.j;
}

int flag2(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case '+': var.j++;
        while (format[var.j + 1] == ' ' || format[var.j + 1] == '+'
        || my_char_isnum(format[var.j + 1])) {
            var.j++;
        }
        specifier_more(var, format, ap, result); break;
    case ' ':
        while (format[var.j + 1] == ' ')
            var.j++;
        if (!check_flags2(format[var.j + 1])
            && !my_char_isnum(format[var.j + 1])) {
            var.j = specifier_space(var, format, ap, result);
        } else {
            var.j = flag(var, format, ap, result);
        } break;
    default:
        var.j = flag3(var, format, ap, result);
    }
    return var.j;
}

int flag(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case '-':
        var.j++;
        while (format[var.j + 1] == ' ' || format[var.j + 1] == '-')
            var.j++;
        if (my_char_isnum(format[var.j + 1])) {
            char *array = malloc(sizeof(char) * (my_strlen(format) + 1));
            var.j = get_width(var, format, array);
            var.width = my_getnbr(array);
            free(array);
            while (check_flags(format[var.j] - 97))
                var.j++;
            var.j = specifier_less(var, format, ap, result);
        } else
            specifier(var, format, ap, result);
        break;
    default:
        var.j = flag2(var, format, ap, result);
    }
    return var.j;
}
