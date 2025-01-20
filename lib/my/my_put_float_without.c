/*
** EPITECH PROJECT, 2024
** my_put_float_without0
** File description:
** putfloat special for g no unused 0
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>

double negative_without_f(double nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        }
        return nb;
}

void stop_and_print(double part_int, double temp_check, int checker, int count)
{
    for (int i = 0; i <= 5; i++) {
        temp_check = temp_check - ((int)(temp_check + 0.1));
        temp_check = ((temp_check) * 10);
        if (((int)temp_check % 10) > 0) {
            checker = i;
        }
    }
    part_int += arrondis(checker);
    for (int j = 0; j <= checker - 1; j++) {
        part_int = part_int - ((int)(part_int));
        part_int = ((part_int) * 10);
        count += my_putchar((part_int) + '0');
    }
}

int my_put_float_without(double nb)
{
    int count = 0;
    int checker = 0;
    double part_int;
    double temp_check = 0;

    nb = negative_without_f(nb);
    count += my_put_nbr(nb);
    if ((nb -(int)nb) == 0) {
        return count;
    }
    count += my_putchar('.');
    part_int = nb;
    temp_check = part_int;
    stop_and_print(part_int, temp_check, checker, count);
    return count;
}
