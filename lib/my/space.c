/*
** EPITECH PROJECT, 2022
** space.c
** File description:
** space
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

void space_less(var_t var, int *result, int result_base)
{
    result_base = *result - result_base;
    for (int i = 0; i < var.width - result_base; i++)
        *result += my_putchar(' ');
}
