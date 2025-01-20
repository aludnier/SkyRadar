/*
** EPITECH PROJECT, 2024
** my_scient
** File description:
** scientific notations
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>

double negative_upper(double nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    return nb;
}

int whole_part_upper(double *nb, int count)
{
    while ((int) *nb > 10) {
        (*nb /= 10);
        count++;
    }
    if ((int) *nb == 0) {
        do {
            (*nb *= 10);
            count--;
            } while ((int) *nb == 0);
    }
    return count;
}

void display_upper(int count)
{
    if (count >= 0 && count < 10) {
        my_putchar('+');
        my_putchar('0');
    }
    if (count < 0 && count > -10) {
        my_putchar('-');
        my_putchar('0');
        count = -count;
    }
    my_put_nbr(count);
}

void my_scient_upper(double nb, int spe)
{
    int count = 0;
    double part_int = 0;

    nb = negative_upper(nb);
    count = (whole_part_upper(&nb, count));
    nb += arrondis(spe + 1);
    if ((int)nb >= 0 && (int)nb < 10)
        my_putchar((int)(nb + 0.1) + '0');
    if (spe != -1){
        my_putchar('.');
    }
    part_int = nb;
    for (int i = 0; i <= spe; i++) {
        part_int = part_int - ((int)(part_int));
        part_int = ((part_int) * 10);
        my_putchar((part_int) + '0');
    }
    my_putchar('E');
    display_upper(count);
}
