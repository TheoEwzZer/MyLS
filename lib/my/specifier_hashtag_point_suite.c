/*
** EPITECH PROJECT, 2022
** specifier_hashtag_point_suite.c
** File description:
** specifier_hashtag_point_suite.c
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int specifier_hashtag_point8(var_t var,
const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'E':
        double E = va_arg(ap, double);
        if (!var.width)
            *result += upper_e_flag_hashtag(E, var.width);
        else
            *result += upper_e_flag(E, var.width);
        break;
    default:
        *result += my_putchar('%');
        *result += my_putchar(format[var.j + 1]);
    }
    return var.j;
}

int specifier_hashtag_point7(var_t var,
const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'e':
        double e = va_arg(ap, double);
        if (!var.width)
            *result += e_flag_hashtag(e, var.width);
        else
            *result += e_flag(e, var.width);
        break;
        var.j = specifier_hashtag_point8(var, format, ap, result);
    }
    return var.j;
}

int specifier_hashtag_point6(var_t var,
const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'u':
        *result += my_putnbr_base(va_arg(ap, int), "0123456789", 0);
        break;
    case 'c':
        *result += my_putchar(va_arg(ap, int));
        break;
    case 's':
        char *s = va_arg(ap, char *);
        *result += my_putstr_point(var, s);
        break;
    default:
        var.j = specifier_hashtag_point7(var, format, ap, result);
    }
    return var.j;
}
