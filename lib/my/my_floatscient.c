/*
** EPITECH PROJECT, 2024
** my_float_science
** File description:
** choose between flag F and E
*/

#include "my.h"
#include <unistd.h>

void my_float_scient(double nb, int spe)
{
    double checker = nb;
    int count = 0;

    while ((int) checker > 10) {
        (checker /= 10);
        count++;
    }
    while ((int) checker == 0) {
        (checker *= 10);
        count--;
    }
    if (count < -4 || count > 5) {
        my_scient(nb, spe);
        } else {
            my_put_float_without(nb);
            }
}
