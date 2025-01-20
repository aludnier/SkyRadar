/*
** EPITECH PROJECT, 2024
** my_put_unsigned
** File description:
** display unisgned int
*/

#include <unistd.h>
#include "my.h"

int my_put_unsigned(long int nb)
{
    int i = 1;

    if (nb <= -4294967295 || nb >= 4294967295) {
        nb = (unsigned int) nb;
    }
    if (nb < 0) {
        nb = 4294967296 + nb;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
        return i;
        }
    i += my_put_unsigned(nb / 10);
    my_putchar((nb % 10) + 48);
    return i;
}
