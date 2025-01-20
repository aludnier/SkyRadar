/*
** EPITECH PROJECT, 2024
** print plus
** File description:
** easy format file*
*/

#include "my.h"

int print_hash(char d)
{
    if (d == '0') {
        my_putchar('0');
        return 1;
    }
    if (d == 'x') {
        my_putstr("0x");
        return 2;
    }
    if (d == 'X') {
        my_putstr("0X");
        return 2;
    }
    return 0;
}

int print_showsign(int nb)
{
    if (nb >= 0) {
        my_putchar('+');
        return 1;
    }
    return 0;
}

int print_space(char *str, int nb)
{
    if (my_strlen(str) < 1 || nb >= 0) {
        my_putchar(' ');
        return 1;
    }
    return 0;
}
