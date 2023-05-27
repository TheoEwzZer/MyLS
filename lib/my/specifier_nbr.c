/*
** EPITECH PROJECT, 2022
** specifier_nbr.c
** File description:
** specifier_nbr
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int specifier_nbr5(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'u': int u = va_arg(ap, int);
        *result += my_putnbr_base_zero(u, "0123456789", 0);
        space_less(var, result, result_base);
        my_putnbr_base(u, "0123456789", 0);
        break;
    case 'S':
        char *S = va_arg(ap, char *);
        *result += s_flag_zero(S);
        space_less(var, result, result_base);
        s_flag(S);
        break;
    case 'l':
        var.j = flag(var, format, ap, result);
        break;
    default:
        var.j = specifier_nbr6(var, format, ap, result);
    }
    return var.j;
}

int specifier_nbr4(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case '%':
        *result += my_putchar('%');
        break;
    case 'i':
    case 'd':
        int d = va_arg(ap, int);
        if (d < 0) {
            d = -d;
            *result += my_putchar('-');
        }
        *result += my_put_nbr_zero(d, 0);
        space_less(var, result, result_base);
        my_put_nbr(d, 0);
        break;
    default:
        var.j = specifier_nbr5(var, format, ap, result);
    }
    return var.j;
}

int specifier_nbr3(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'b':
        int b = va_arg(ap, int);
        *result += my_putnbr_base_zero(b, "01", 0);
        space_less(var, result, result_base);
        my_putnbr_base(b, "01", 0);
        break;
    default:
        var.j = specifier_nbr4(var, format, ap, result);
    }
    return var.j;
}

int specifier_nbr2(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'x':
        int x = va_arg(ap, int);
        *result += my_putnbr_base_zero(x, "0123456789abcdef", 0);
        space_less(var, result, result_base);
        my_putnbr_base(x, "0123456789abcdef", 0);
        break;
    case 'X':
        int X = va_arg(ap, int);
        *result += my_putnbr_base_zero(X, "0123456789ABCDEF", 0);
        space_less(var, result, result_base);
        my_putnbr_base(X, "0123456789ABCDEF", 0);
        break;
    default:
        var.j = specifier_nbr3(var, format, ap, result);
    }
    return var.j;
}

int specifier_nbr(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'p':
        int p = va_arg(ap, int);
        *result += my_put_ptr_zero(p, 2);
        space_less(var, result, result_base);
        my_put_ptr(p, 2);
        *result += 2;
        break;
    case 'c':
        *result += 1;
        space_less(var, result, result_base);
        my_putchar(va_arg(ap, int));
        break;
    default:
        var.j = specifier_nbr2(var, format, ap, result);
    }
    return var.j;
}
