/*
** EPITECH PROJECT, 2022
** specifier_more.c
** File description:
** specifier_more
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int specifier_less5(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case '%':
        *result += my_putchar('%');
        break;
    case 's':
        *result += my_putstr(va_arg(ap, char *));
        space_less(var, result, result_base);
        break;
    case '.':
        var.j = flag(var, format, ap, result);
        space_less(var, result, result_base);
        break;
    default:
        var.j = specifier_less6(var, format, ap, result);
    }
    return var.j;
}

int specifier_less4(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'p':
        *result += my_put_ptr(va_arg(ap, int), 2);
        space_less(var, result, result_base);
        break;
    case 'S':
        *result += s_flag(va_arg(ap, char *));
        space_less(var, result, result_base);
        break;
    case 'u':
        *result += my_putnbr_base(va_arg(ap, int), "0123456789", 0);
        space_less(var, result, result_base);
        break;
    default:
        var.j = specifier_less5(var, format, ap, result);
    }
    return var.j;
}

int specifier_less3(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'F':
    case 'f':
        *result += my_putfloat(va_arg(ap, double), 6);
        space_less(var, result, result_base); break;
    case 'e':
        *result += e_flag(va_arg(ap, double), 6);
        space_less(var, result, result_base); break;
    case 'E':
        *result += upper_e_flag(va_arg(ap, double), 6);
        space_less(var, result, result_base); break;
    case 'b':
        *result += my_putnbr_base(va_arg(ap, int), "01", 0);
        space_less(var, result, result_base); break;
    default:
        var.j = specifier_less4(var, format, ap, result);
    }
    return var.j;
}

int specifier_less2(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'o':
        *result += my_putnbr_base(va_arg(ap, int), "01234567", 0);
        space_less(var, result, result_base);
        break;
    case 'x':
        *result += my_putnbr_base(va_arg(ap, int), "0123456789abcdef", 0);
        space_less(var, result, result_base);
        break;
    case 'X':
        *result += my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF", 0);
        space_less(var, result, result_base);
        break;
    default:
        var.j = specifier_less3(var, format, ap, result);
    }
    return var.j;
}

int specifier_less(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'i':
    case 'd':
        *result += my_put_nbr(va_arg(ap, int), 0);
        space_less(var, result, result_base);
        break;
    case 'c':
        *result += my_putchar(va_arg(ap, int));
        space_less(var, result, result_base);
        break;
    case '\0':
        var.j = -1;
        break;
    default:
        var.j = specifier_less2(var, format, ap, result);
    }
    return var.j;
}
