/*
** EPITECH PROJECT, 2022
** conversion_zero.c
** File description:
** conversion_zero.c
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

int my_putstr_zero(char const *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count ++;
    }
    return count;
}

void space_zero(var_t var, int *result, int result_base)
{
    result_base = *result - result_base;
    for (int i = 0; i < var.width - result_base; i++)
        *result += my_putchar('0');
}

int my_put_nbr_zero(int nbr, int count)
{
    int quotient = nbr / 10;
    if (quotient != 0) {
        count = my_put_nbr_zero(quotient, count);
    }
    count++;
    return count;
}

int my_putnbr_base_zero(unsigned int nbr, char *base, int count)
{
    int len = my_strlen(base);
    int quotient = nbr / len;
    if (quotient != 0) {
        count = my_putnbr_base_zero(quotient, base, count);
    }
    count++;
    return count;
}

int my_put_ptr_zero(unsigned int nbr, int count)
{
    int quotient = nbr / 16;
    if (quotient != 0)
        count = my_put_ptr_zero(quotient, count);
    count++;
    return count;
}
