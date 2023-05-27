/*
** EPITECH PROJECT, 2022
** specifier_space.c
** File description:
** specifier_space
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int specifier_space5(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'e':
        double e = va_arg(ap, double);
        if (e >= 0)
            *result += my_putchar(' ');
        *result += e_flag(e, 6);
        break;
    case 'E':
        double E = va_arg(ap, double);
        if (E >= 0)
            *result += my_putchar(' ');
        *result += upper_e_flag(E, 6);
        break;
    default:
        *result += my_putchar('%');
        *result += my_putchar(format[var.j + 1]);
    }
    return var.j;
}

int specifier_space4(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 's':
        *result += my_putstr(va_arg(ap, char *));
        break;
    case '%':
        *result += my_putchar('%');
        break;
    case '.':
        var.j = flag(var, format, ap, result);
        break;
    case 'l':
        var.j = flag(var, format, ap, result);
        break;
    case 'n':
        *(va_arg(ap, int *)) = *result; break;
    default:
        var.j = specifier_space5(var, format, ap, result);
    }
    return var.j;
}

int specifier_space3(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'F':
    case 'f':
        double f = va_arg(ap, double);
        if (f >= 0)
            *result += my_putchar(' ');
        *result += my_putfloat(f, 6);
        break;
    case 'b':
        *result += my_putnbr_base(va_arg(ap, int), "01", 0); break;
    case 'p':
        int p = va_arg(ap, int);
        if (p >= 0)
            *result += my_putchar(' ');
        *result += my_put_ptr(p, 2);
        break;
    default:
        var.j = specifier_space4(var, format, ap, result);
    }
    return var.j;
}

int specifier_space2(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'o':
        *result += my_putnbr_base(va_arg(ap, int), "01234567", 0);
        break;
    case 'x':
        *result += my_putnbr_base(va_arg(ap, int), "0123456789abcdef", 0);
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
        var.j = specifier_space3(var, format, ap, result);
    }
    return var.j;
}

int specifier_space(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'i':
    case 'd':
        int d = va_arg(ap, int);
        if (d >= 0)
            *result += my_putchar(' ');
        *result += my_put_nbr(d, 0);
        break;
    case 'c':
        *result += my_putchar(va_arg(ap, int));
        break;
    case '\0':
        var.j = -1;
        break;
    default:
        var.j = specifier_space2(var, format, ap, result);
    }
    return var.j;
}
