/*
** EPITECH PROJECT, 2022
** specifier_zero_suite.c
** File description:
** specifier_zero_suite.c
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

void specifier_zero9(var_t var, const char *format, va_list ap, int *result)
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
        space_zero(var, result, result_base);
        e_flag(E, 6);
        break;
    default:
        *result += my_putchar('%');
        *result += my_putchar(format[var.j + 1]);
    }
}

void specifier_zero8(var_t var, const char *format, va_list ap, int *result)
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
        space_zero(var, result, result_base);
        e_flag(e, 6);
        break;
    default:
        specifier_zero9(var, format, ap, result);
    }
}

void specifier_zero7(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 's':
        char *s = va_arg(ap, char *);
        *result += my_putstr_zero(s);
        space_less(var, result, result_base);
        my_putstr(s);
        break;
    case 'b':
        int b = va_arg(ap, int);
        *result += my_putnbr_base_zero(b, "01", 0);
        space_zero(var, result, result_base);
        my_putnbr_base(b, "01", 0);
        break;
    case 'n':
        *(va_arg(ap, int *)) = *result; break;
    default:
        specifier_zero8(var, format, ap, result);
    }
}

void specifier_zero6(var_t var, const char *format, va_list ap, int *result)
{
    int result_base = *result;
    switch (format[var.j + 1]) {
    case 'o':
        int o = va_arg(ap, int);
        *result += my_putnbr_base_zero(o, "01234567", 0);
        space_zero(var, result, result_base);
        my_putnbr_base(o, "01234567", 0);
        break;
    case '\0':
        var.j = -1;
        break;
    default:
        specifier_zero7(var, format, ap, result);
    }
}
