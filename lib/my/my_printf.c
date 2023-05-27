/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** Printf.
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int my_printf2(var_t var, const char *format, va_list ap, int *result)
{
    if (format[var.j] == '%') {
        var.j = flag(var, format, ap, result);
        if (var.j == -1)
            return -1;
        var.j++;
    } else {
        *result += my_putchar(format[var.j]);
    }
    return var.j;
}

int my_printf(const char *format, ...)
{
    var_t var;
    var.j = 0;
    var.width = 0;
    var.hashtag = 0;
    int result = 0;
    va_list ap;
    va_start(ap, format);
    for (; format[var.j]; var.j++) {
        var.j = my_printf2(var, format, ap, &result);
        if (var.j == -1)
            return -1;
    }
    va_end(ap);
    return result;
}
