/*
** EPITECH PROJECT, 2024
** print basics
** File description:
** mini_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

static void prec_int(specifier_t spe, int *count, int nb)
{
    if (len_nb(nb) > spe.prec)
        spe.prec = len_nb(nb);
    while (spe.prec - len_nb(nb) > 0){
        *count += my_putchar('0');
        spe.prec = spe.prec - 1;
    }
}

void print_width(int width, int *count, int len)
{
    while (width > len){
        *count += my_putchar(' ');
        width--;
    }
}

int print_string(va_list ap, specifier_t spe)
{
    char *str = va_arg(ap, char *);
    int count = 0;
    int index = 0;

    if (spe.prec == -1)
        spe.prec = my_strlen(str);
    print_width(spe.width, &count, spe.prec);
    if (spe.space == 1)
        print_space(str, -1);
    while (spe.prec > 0 && str[index] != '\0'){
        count += my_putchar(str[index]);
        spe.prec -= 1;
        index++;
    }
    return count;
}

int print_int(va_list ap, specifier_t spe)
{
    int nb = va_arg(ap, int);
    int count = 0;

    if (spe.showsign == 1)
        print_showsign(nb);
    if (spe.space == 1)
        print_space(" ", nb);
    if (nb < 0){
        print_width(spe.width, &count, spe.prec + 1);
        count += my_putstr("-");
        nb *= -1;
    } else {
        print_width(spe.width, &count, spe.prec);
    }
    prec_int(spe, &count, nb);
    return count + my_put_nbr(nb);
}

int print_unsigned(va_list ap, specifier_t spe)
{
    int nb = va_arg(ap, unsigned int);
    int count = 0;

    if (spe.showsign == 1)
        print_showsign(nb);
    if (spe.space == 1)
        print_space(" ", nb);
    print_width(spe.width, &count, spe.prec);
    prec_int(spe, &count, nb);
    return count + my_put_unsigned(nb);
}
