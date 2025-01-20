/*
** EPITECH PROJECT, 2024
** conv_to_hex
** File description:
** conv to hexadecimal
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int len_nb(unsigned int nb)
{
    int len = 0;

    if (nb == 0){
        return 1;
    }
    while (nb > 0){
        len++;
        nb /= 10;
    }
    return len;
}

char *conv_to_hex(unsigned long nb)
{
    int len = len_nb(nb);
    char *hexa = malloc(sizeof(char) * len);
    int conv = 0;
    int i = 0;

    if (nb == 0)
        return "0";
    while (nb > 0){
        if (nb % 16 < 10){
            conv = nb % 16 + 48;
        } else {
            conv = nb % 16 + 55;
        }
        hexa[i] = conv;
        i++;
        nb /= 16;
    }
    return my_revstr(hexa);
}

static int conv_rigth_form(double *nb, int *index, char *str)
{
    int count_p = 0;

    if (*nb < 0){
        str[*index] = '-';
        *index += 1;
        *nb *= -1;
    }
    while (*nb < 1.0){
        count_p -= 1;
        *nb *= 2;
    }
    while (*nb >= 2.0){
        count_p += 1;
        *nb /= 2;
    }
    return count_p;
}

static void init_str(char *str, int *index, double *nb)
{
    str[*index] = '0';
    str[*index + 1] = 'X';
    str[*index + 2] = '1';
    str[*index + 3] = '.';
    *index += 4;
    *nb -= 1;
}

int rev_nbr(int nb)
{
    int rev_nb = 0;

    while (nb > 0){
        rev_nb = (rev_nb + (nb % 10)) * 10;
        nb /= 10;
    }
    return rev_nb / 10;
}

static void add_power(char *str, int index, int count_p)
{
    if (str[index - 1] == '.')
        index--;
    str[index] = 'P';
    if (count_p > 0){
        str[index + 1] = '+';
    } else {
        str[index + 1] = '-';
        count_p *= -1;
    }
    count_p = rev_nbr(count_p);
    while (count_p > 0){
        str[index + 2] = 48 + (count_p % 10);
        index++;
        count_p /= 10;
    }
}

void arrond_hexa(char *str, int *index)
{
    char val_arr = str[*index - 1];

    *index -= 1;
    if (str[*index - 1] == '.')
        *index -= 1;
    if (val_arr >= '8'){
        if (str[*index - 1] == '9'){
            str[*index - 1] = 'A';
            return;
        }
        str[*index - 1] = (int)(str[*index - 1]) + 1;
    }
    str[*index + 1] = '\0';
}

char *conv_post_coma(double nb, int spe)
{
    char *hexa = malloc(sizeof(char) * 30);
    int index = 0;
    int count_p = conv_rigth_form(&nb, &index, hexa);
    int max = 0;

    init_str(hexa, &index, &nb);
    max = index + spe;
    while (index <= max + 1){
        if ((int) (nb * 16) < 10){
            hexa[index] = (int) (nb * 16) + 48;
        } else {
            hexa[index] = (int) (nb * 16) + 55;
        }
        nb = nb * 16.0;
        nb -= (int) nb;
        index++;
    }
    arrond_hexa(hexa, &index);
    add_power(hexa, index, count_p);
    return hexa;
}
