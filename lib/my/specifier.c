/*
** EPITECH PROJECT, 2022
** specifier.c
** File description:
** specifier
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

void specifier4(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'F':
    case 'f':
        *result += my_putfloat(va_arg(ap, double), 6);
        break;
    case 'e':
        *result += e_flag(va_arg(ap, double), 6);
        break;
    case 'E':
        *result += upper_e_flag(va_arg(ap, double), 6);
        break;
    default:
        *result += my_putchar('%');
        *result += my_putchar(format[var.j + 1]);
    }
}

void specifier3(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'b':
        *result += my_putnbr_base(va_arg(ap, int), "01", 0);
        break;
    case 'p':
        *result += my_put_ptr(va_arg(ap, int), 2);
        break;
    case '%':
        *result += my_putchar('%');
        break;
    case 'n':
        *(va_arg(ap, int *)) = *result; break;
    default:
        specifier4(var, format, ap, result);
    }
}

void specifier2(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'o':
        *result += my_putnbr_base(va_arg(ap, int), "01234567", 0);
        break;
    case 'x':
        *result += my_putnbr_base(va_arg(ap, long), "0123456789abcdef", 0);
        break;
    case 'X':
        *result += my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF", 0);
        break;
    case 'u':
        *result += my_putnbr_base(va_arg(ap, int), "0123456789", 0);
        break;
    case 'S':
        *result += s_flag(va_arg(ap, char *));
        break;
    default:
        specifier3(var, format, ap, result);
    }
}

int specifier(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'i':
    case 'd':
        *result += my_put_nbr(va_arg(ap, int), 0);
        break;
    case 'c':
        *result += my_putchar(va_arg(ap, int));
        break;
    case 's':
        char *s = va_arg(ap, char *);
        my_putstr(s);
        *result += my_strlen(s);
        break;
    case '\0':
        var.j = -1;
        break;
    default:
        specifier2(var, format, ap, result);
    }
    return var.j;
}
