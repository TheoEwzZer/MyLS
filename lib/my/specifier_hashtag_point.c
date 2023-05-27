/*
** EPITECH PROJECT, 2022
** specifier_hashtag_point.c
** File description:
** specifier_hashtag_point
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int specifier_hashtag_point5(var_t var,
const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case '%':
        *result += my_putchar('%');
        break;
    case 'p':
        int p = va_arg(ap, int);
        my_putstr("0x");
        *result += my_put_ptr_zero(p, 2);
        space_zero(var, result, result_base);
        my_put_ptr(p, 2);
        *result += 2;
        break;
    case 'n':
        *(va_arg(ap, int *)) = *result;
        break;
    default:
        var.j = specifier_hashtag_point6(var, format, ap, result);
    }
    return var.j;
}

int specifier_hashtag_point4(var_t var,
const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'X':
        int X = va_arg(ap, int);
        if (X != 0)
            my_putstr("0X");
        *result += my_putnbr_base(X, "0123456789ABCDEF", 0);
        break;
    case 'S':
        *result += s_flag(va_arg(ap, char *));
        break;
    case '.':
        var.j = flag4(var, format, ap, result);
        break;
    default:
        var.j = specifier_hashtag_point5(var, format, ap, result);
    }
    return var.j;
}

int specifier_hashtag_point3(var_t var,
const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'o':
        int o = va_arg(ap, int);
        if (o != 0)
            my_putchar('0');
        *result += my_putnbr_base(o, "01234567", 0);
        break;
    case 'x':
        int x = va_arg(ap, int);
        if (x != 0)
            my_putstr("0x");
        *result += my_putnbr_base(x, "0123456789abcdef", 0);
        break;
    default:
        var.j = specifier_hashtag_point4(var, format, ap, result);
    }
    return var.j;
}

int specifier_hashtag_point2(var_t var,
const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'F':
    case 'f':
        *result += my_putfloat(va_arg(ap, double), var.width);
        if (!var.width)
            my_putchar('.');
        break;
    case 'b':
        int b = va_arg(ap, int);
        if (b != 0)
            my_putstr("0b");
        *result += my_putnbr_base_zero(b, "01", 0);
        space_zero(var, result, result_base);
        my_putnbr_base(b, "01", 0);
        *result += 2; break;
    default:
        var.j = specifier_hashtag_point3(var, format, ap, result);
    }
    return var.j;
}

int specifier_hashtag_point(var_t var,
const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'i':
    case 'd':
        int d = va_arg(ap, int);
        if (d < 0) {
            d = -d;
            *result += my_putchar('-');
        }
        *result += my_put_nbr_zero(d, 0);
        space_zero(var, result, result_base);
        my_put_nbr(d, 0);
        break;
    case '\0':
        var.j = -1;
        break;
    default:
        var.j = specifier_hashtag_point2(var, format, ap, result);
    }
    return var.j;
}
