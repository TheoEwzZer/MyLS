/*
** EPITECH PROJECT, 2022
** my_putfloat_zero.c
** File description:
** return number of caracter of a float
*/

#include "my.h"

int my_putfloat_zero3(double decimal, int n, int count, double nb)
{
    if ((nb - ((int)nb)) < 0.1 && (nb - ((int)nb)) > 0) {
        float nbr = (nb - (long)nb);
        nbr *= 10;
        for (int i = 1; nbr <= 0.999999 && i <= n - 1 && decimal != 0; i++) {
            count++;
            nbr *= 10;
        }
    }
    if (decimal != 0 && decimal != 1) {
        count += my_put_nbr_zero(decimal, 0);
    }
    return count;
}

int my_putfloat_zero2(double decimal, int n, int count, double nb)
{
    int more = 0;
    if (!decimal) {
        for (int i = 0; i < n; i++) {
            count++;
            more = 1;
        }
    }
    double decimal3 = nb - (long)nb;
    int decimal2 = decimal3 * my_compute_power_rec(10, n + 1);
    int next = decimal2 % 10;
    if (next >= 5)
        more = 1;
    if (more)
        decimal++;
    return my_putfloat_zero3(decimal, n, count, nb);
}

int my_putfloat_zero(double nb, int n)
{
    int count = 0;
    if (nb < 0) {
        count++;
        nb = -nb;
    }
    double decimal4 = nb - (long)nb;
    double decimal = decimal4 * my_compute_power_rec(10, n);
    if (!n) {
        if ((nb - (int)nb) * 10 >= 5) {
            nb++;
        }
        count += my_put_nbr_zero((int)nb, 0);
    } else {
        count += my_put_nbr_zero((int)nb, 0) + 1;
        count = my_putfloat_zero2(decimal, n, count, nb);
    }
    return count;
}
