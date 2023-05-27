/*
** EPITECH PROJECT, 2022
** specifier_hashtag.c
** File description:
** specifier_hashtag
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int specifier_hashtag5(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case '.':
        var.hashtag = 1;
        var.j = flag4(var, format, ap, result);
        break;
    case '-':
        var.j = flag(var, format, ap, result);
        break;
    case 'u':
        *result += my_putnbr_base(va_arg(ap, int), "0123456789", 0);
        break;
    case 'n':
        *(va_arg(ap, int *)) = *result;
        break;
    default:
        *result += my_putchar('%');
        *result += my_putchar(format[var.j + 1]);
    }
    return var.j;
}

int specifier_hashtag4(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'X':
        int X = va_arg(ap, int);
        if (X != 0)
            *result += my_putstr("0X");
        *result += my_putnbr_base(X, "0123456789ABCDEF", 0);
        break;
    case 'S':
        *result += s_flag(va_arg(ap, char *));
        break;
    case '%':
        *result += my_putchar('%');
        break;
    default:
        var.j = specifier_hashtag5(var, format, ap, result);
    }
    return var.j;
}

int specifier_hashtag3(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'o':
        int o = va_arg(ap, int);
        if (o != 0)
            *result += my_putchar('0');
        *result += my_putnbr_base(o, "01234567", 0);
        break;
    case 'x':
        int x = va_arg(ap, int);
        if (x != 0)
            *result += my_putstr("0x");
        *result += my_putnbr_base(x, "0123456789abcdef", 0);
        break;
    default:
        var.j = specifier_hashtag4(var, format, ap, result);
    }
    return var.j;
}

int specifier_hashtag2(var_t var, const char *format, va_list ap, int *result)
{
    switch (format[var.j + 1]) {
    case 'F':
    case 'f':
        *result += my_putfloat(va_arg(ap, double), 6); break;
    case 'e':
        *result += e_flag(va_arg(ap, double), 6); break;
    case 'E':
        *result += upper_e_flag(va_arg(ap, double), 6); break;
    case 'b':
        int b = va_arg(ap, int);
        if (b != 0)
            *result += my_putstr("0b");
        *result += my_putnbr_base(b, "01", 0);
        break;
    case 'p':
        *result += my_put_ptr(va_arg(ap, int), 2); break;
    default:
        var.j = specifier_hashtag3(var, format, ap, result);
    }
    return var.j;
}

int specifier_hashtag(var_t var, const char *format, va_list ap, int *result)
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
        *result += my_putstr(s);
        break;
    case '\0':
        var.j = -1;
        break;
    default:
        var.j = specifier_hashtag2(var, format, ap, result);
    }
    return var.j;
}
