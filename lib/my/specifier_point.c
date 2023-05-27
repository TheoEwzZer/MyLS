/*
** EPITECH PROJECT, 2022
** specifier_point.c
** File description:
** specifier_point
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

void specifier_point5(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'u':
        int u = va_arg(ap, int);
        *result += my_putnbr_base_zero(u, "0123456789", 0);
        space_zero(var, result, result_base);
        my_putnbr_base(u, "0123456789", 0);
        break;
    case 'S':
        *result += s_flag_point(var, va_arg(ap, char *));
        break;
    default:
        specifier_point6(var, format, ap, result);
    }
}

void specifier_point4(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case '%':
        *result += my_putchar('%');
        break;
    case 'i':
    case 'd':
        int d = va_arg(ap, int);
        *result += my_put_nbr_zero(d, 0);
        space_zero(var, result, result_base);
        my_put_nbr(d, 0);
        break;
    default:
        specifier_point5(var, format, ap, result);
    }
}

void specifier_point3(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'F':
    case 'f':
        *result += my_putfloat(va_arg(ap, double), var.width); break;
    case 'e':
        *result += e_flag(va_arg(ap, double), var.width);
        break;
    case 'E':
        *result += upper_e_flag(va_arg(ap, double), var.width);
        break;
    case 'b':
        int b = va_arg(ap, int);
        *result += my_putnbr_base_zero(b, "01", 0);
        space_zero(var, result, result_base);
        my_putnbr_base(b, "01", 0);
        break;
    default:
        specifier_point4(var, format, ap, result);
    }
}

void specifier_point2(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'x':
        int x = va_arg(ap, int);
        *result += my_putnbr_base_zero(x, "0123456789abcdef", 0);
        space_zero(var, result, result_base);
        my_putnbr_base(x, "0123456789abcdef", 0);
        break;
    case 'X':
        int X = va_arg(ap, int);
        *result += my_putnbr_base_zero(X, "0123456789ABCDEF", 0);
        space_zero(var, result, result_base);
        my_putnbr_base(X, "0123456789ABCDEF", 0);
        break;
    case 's':
        *result += my_putstr_point(var, va_arg(ap, char *));
        break;
    default:
        specifier_point3(var, format, ap, result);
    }
}

int specifier_point(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'p':
        int p = va_arg(ap, int);
        my_putstr("0x");
        *result += my_put_ptr_zero(p, 0);
        space_zero(var, result, result_base);
        my_put_ptr(p, 3);
        *result += 2;
        break;
    case 'c':
        *result += my_putchar(va_arg(ap, int));
        break;
    default:
        specifier_point2(var, format, ap, result);
    }
    return var.j;
}
