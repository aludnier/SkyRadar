/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** print an number
*/

#include <unistd.h>
#include "my.h"

int my_put_nbr(int nb)
{
    int i = 1;

    if (nb < -2147483647 || nb > 2147483647) {
        return 0;
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb < 10) {
        my_putchar(nb + '0');
        return i;
    }
    i += my_put_nbr(nb / 10);
    my_putchar((nb % 10) + '0');
    return i;
}
