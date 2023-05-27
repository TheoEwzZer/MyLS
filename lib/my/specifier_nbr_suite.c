/*
** EPITECH PROJECT, 2022
** specifier_nbr_suite.c
** File description:
** specifier_nbr_suite
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int specifier_nbr10(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'E':
        double E = va_arg(ap, double);
        if (E < 0) {
            E = -E;
            *result += my_putchar('-');
        }
        *result += e_flag_zero(E, 6);
        space_less(var, result, result_base);
        upper_e_flag(E, 6);
        break;
    default:
        *result += my_putchar('%');
        *result += my_put_nbr(var.width, 0);
        *result += my_putchar(format[var.j + 1]);
    }
    return var.j;
}

int specifier_nbr9(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'e':
        double e = va_arg(ap, double);
        if (e < 0) {
            e = -e;
            *result += my_putchar('-');
        }
        *result += e_flag_zero(e, 6);
        space_less(var, result, result_base);
        e_flag(e, 6);
        break;
    default:
        var.j = specifier_nbr10(var, format, ap, result);
    }
    return var.j;
}

int specifier_nbr8(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'F':
    case 'f':
        double f = va_arg(ap, double);
        if (f < 0) {
            f = -f;
            *result += my_putchar('-');
        }
        *result += my_putfloat_zero(f, 6);
        space_less(var, result, result_base);
        my_putfloat(f, 6); break;
    case 'n':
        *(va_arg(ap, int *)) = *result; break;
    default:
        var.j = specifier_nbr9(var, format, ap, result);
    }
    return var.j;
}

int specifier_nbr7(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 's': char *s = va_arg(ap, char *);
        *result += my_putstr_zero(s);
        space_less(var, result, result_base);
        my_putstr(s);
        break;
    case '.':
        space_less(var, result, result_base);
        var.j = flag3(var, format, ap, result);
        break;
    case 'l':
        var.j = flag(var, format, ap, result);
        break;
    default:
        var.j = specifier_nbr8(var, format, ap, result);
    }
    return var.j;
}

int specifier_nbr6(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'o':
        int o = va_arg(ap, int);
        *result += my_putnbr_base_zero(o, "01234567", 0);
        space_less(var, result, result_base);
        my_putnbr_base(o, "01234567", 0);
        break;
    case '.':
        space_less(var, result, result_base);
        var.j = flag(var, format, ap, result);
        break;
    case '\0':
        var.j = -1;
        break;
    default:
        var.j = specifier_nbr7(var, format, ap, result);
    }
    return var.j;
}
