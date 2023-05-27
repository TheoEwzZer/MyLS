/*
** EPITECH PROJECT, 2022
** e_flag_zero.c.c
** File description:
** e_flag_zero
*/

#include "my.h"

int e_flag_2_zero(int count, int c)
{
    count += 2;
    if (c < 10)
        count++;
    count += my_put_nbr_zero(c, 0);
    return count;
}

int e_flag_zero(double nb, int n)
{
    int count = 0;
    int c = 0;
    if (nb < 0) {
        count++;
        nb = -nb;
    } if (nb >= 1) {
        while (nb >= 10) {
            nb /= 10;
            c++;
        }
    } if (nb < 1 && nb > 0) {
        while (nb < 1) {
            nb *= 10;
            c++;
        }
    }
    count += my_putfloat_zero(nb, n);
    return e_flag_2_zero(count, c);
}
