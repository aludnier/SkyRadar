/*
** EPITECH PROJECT, 2024
** my_put_float
** File description:
** display decimal number
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>

int my_put_float(double nb, int spe)
{
    double part_int;
    int count = 0;

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    nb = nb + arrondis(spe + 1);
    count += my_put_nbr(nb);
    if (spe != -1)
        count += my_putchar('.');
    part_int = nb;
    for (int i = 0; i <= spe; i++) {
        part_int = part_int - ((int)part_int);
        part_int = ((part_int) * 10);
        count += my_putchar((part_int) + '0');
    }
    return count;
}
