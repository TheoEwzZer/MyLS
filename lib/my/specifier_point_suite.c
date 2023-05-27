/*
** EPITECH PROJECT, 2022
** specifier_point_suite.c
** File description:
** specifier_point_suite
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

int my_putstr_point(var_t var, char const *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0' && i < var.width; i++) {
        count += my_putchar(str[i]);
    }
    return count;
}

int s_flag_point(var_t var, char *str)
{
    int count = 0;
    char *array = malloc(sizeof(char) * 5);
    reset_array(array);
    for (int i = 0; str[i] != '\0' && i < var.width; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            count += my_putchar('\\');
            count += my_putnbr_base_s(str[i], "01234567", 0, array);
            count = zero_before(array, count);
            my_putstr(array);
            reset_array(array);
        } else {
            count += my_putchar(str[i]);
        }
    }
    free(array);
    return count;
}

void specifier_point6(var_t var, const char *format, va_list ap, int *result)
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
    case 'n':
        *(va_arg(ap, int *)) = *result;
        break;
    default:
        my_putchar('%');
        my_putchar(format[var.j + 1]);
        *result += 2;
    }
}
