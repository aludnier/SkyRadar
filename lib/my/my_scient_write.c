/*
** EPITECH PROJECT, 2024
** my_scient
** File description:
** scientific notations
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>

double negative(double nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    return nb;
}

int whole_part(double *nb, int count)
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

void display_e(int count)
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

double arrondis(int power)
{
    double ar_nb = 5.0;

    while (power >= 0){
        ar_nb /= 10;
        power--;
    }
    return ar_nb;
}

void my_scient(double nb, int spe)
{
    int count = 0;
    double part_int = 0;

    nb = negative(nb);
    count = (whole_part(&nb, count));
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
    my_putchar('e');
    display_e(count);
}
