/*
** EPITECH PROJECT, 2022
** specifier_less_suite.c
** File description:
** specifier_less_suite
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int specifier_less6(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'l':
        var.j = flag(var, format, ap, result);
        space_less(var, result, result_base);
        break;
    case 'n':
        *(va_arg(ap, int *)) = *result;
        break;
    default:
        *result += my_putstr("%-");
        *result += my_put_nbr(var.width, 0);
        *result += my_putchar(format[var.j + 1]);
    }
    return var.j;
}
