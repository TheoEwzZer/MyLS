/*
** EPITECH PROJECT, 2022
** specifier_long.c
** File description:
** specifier_long
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

void specifier_long3(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'F':
    case 'f':
        *result += my_putfloat(va_arg(ap, long double), 6);
        break;
    case 'e':
        *result += e_flag(va_arg(ap, long double), 6);
        break;
    case 'E':
        *result += upper_e_flag(va_arg(ap, long double), 6);
        break;
    case 'b':
        *result += my_putnbr_base_long(va_arg(ap, long), "01", 0);
        break;
    default:
        *result += my_putchar('%');
        *result += my_putchar(format[var.j + 1]);
    }
}

void specifier_long2(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'o':
        *result += my_putnbr_base_long(va_arg(ap, long), "01234567", 0);
        break;
    case 'x':
        *result += my_putnbr_base_long(va_arg(ap, long), "0123456789abcdef", 0);
        break;
    case 'X':
        *result += my_putnbr_base_long(va_arg(ap, long), "0123456789ABCDEF", 0);
        break;
    case 'u':
        *result += my_putnbr_base_long(va_arg(ap, long), "0123456789", 0);
        break;
    default:
        specifier_long3(var, format, ap, result);
    }
}

int specifier_long(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'c':
    case 's':
    case '\0':
    case 'p':
    case '%':
    case 'S':
        var.j = -1;
        break;
    case 'i':
    case 'd':
        *result += my_put_nbr(va_arg(ap, long), 0);
        break;
    default:
        specifier_long2(var, format, ap, result);
    }
    return var.j;
}
