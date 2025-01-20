/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** negative or not
*/
#include "my.h"
int my_isneg(int n)
{
    if (n < 0){
        my_putchar(78);
    } else {
        my_putchar(80);
    }
    return 0;
}
