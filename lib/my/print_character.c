/*
** EPITECH PROJECT, 2024
** print_characters
** File description:
** print one char
*/

#include "my.h"

int print_char(va_list ap)
{
    return my_putchar(va_arg(ap, int));
}

int print_percent(void)
{
    my_putchar('%');
    return 1;
}

int print_g(va_list ap, specifier_t spe)
{
    double nb = va_arg(ap, double);
    int count = 0;

    if (spe.prec == -1)
        spe.prec = 6;
    if (nb == 0.0){
        return my_putstr("0.000000E+00");
    }
    if (spe.showsign == 1)
        print_showsign((int) nb);
    if (spe.space == 1)
        print_space(" ", (int) nb);
    print_width(spe.width, &count, spe.prec + len_nb((int)nb) + 5);
    my_float_scient(nb, spe.prec);
    return count;
}
