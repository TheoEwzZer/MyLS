/*
** EPITECH PROJECT, 2022
** e_flag.c
** File description:
** e_flag
*/

#include "my.h"

int e_flag_2(int count, int below, int c)
{
    count += my_putchar('e');
    if (below)
        count += my_putchar('-');
    else
        count += my_putchar('+');
    if (c < 10)
        count += my_putchar('0');
    count += my_put_nbr(c, 0);
    return count;
}

int e_flag(double nb, int n)
{
    int below = 0;
    int count = 0;
    int c = 0;
    if (nb < 0) {
        count += my_putchar('-');
        nb = -nb;
    } if (nb >= 1) {
        while (nb >= 10) {
            nb /= 10;
            c++;
        }
    } if (nb < 1 && nb > 0) {
        below = 1;
        while (nb < 1) {
            nb *= 10;
            c++;
        }
    }
    count += my_putfloat(nb, n);
    return e_flag_2(count, below, c);;
}

int upper_e_flag_2(int count, int below, int c)
{
    count += my_putchar('E');
    if (below)
        count += my_putchar('-');
    else
        count += my_putchar('+');
    if (c < 10)
        count += my_putchar('0');
    count += my_put_nbr(c, 0);
    return count;
}

int upper_e_flag(double nb, int n)
{
    int below = 0;
    int count = 0;
    int c = 0;
    if (nb < 0) {
        count += my_putchar('-');
        nb = -nb;
    } if (nb >= 1) {
        while (nb >= 10) {
            nb /= 10;
            c++;
        }
    } if (nb < 1 && nb > 0) {
        below = 1;
        while (nb < 1) {
            nb *= 10;
            c++;
        }
    }
    count += my_putfloat(nb, n);
    return upper_e_flag_2(count, below, c);
}
