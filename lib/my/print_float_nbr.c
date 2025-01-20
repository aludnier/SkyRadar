/*
** EPITECH PROJECT, 2024
** print_float_nbr
** File description:
** print floating nbr
*/

#include "my.h"
#include <stdarg.h>

int print_float(va_list ap, specifier_t spe)
{
    double nb = va_arg(ap, double);
    int count = 0;

    if (spe.prec == -1)
        spe.prec = 6;
    print_width(spe.width, &count, spe.prec + len_nb((int) nb) + 1);
    if (spe.showsign == 1)
        print_showsign(nb);
    if (spe.space == 1)
        print_space(" ", (int) nb);
    return my_put_float(nb, spe.prec - 1);
}

int print_a_low(va_list ap, specifier_t spe)
{
    double nb = va_arg(ap, double);
    int count = 0;

    if (spe.prec == -1)
        spe.prec = 13;
    if (spe.space == 1)
        print_space(" ", (int) nb);
    print_width(spe.width, &count, spe.prec + 7);
    return count + my_putstr(my_strlowcase(conv_post_coma(nb, spe.prec - 1)));
}

int print_a_upper(va_list ap, specifier_t spe)
{
    double nb = va_arg(ap, double);
    int count = 0;

    if (spe.prec == -1)
        spe.prec = 15;
    if (spe.space == 1)
        print_space(" ", (int) nb);
    print_width(spe.width, &count, spe.prec + 7);
    return count + my_putstr(conv_post_coma(nb, spe.prec - 1));
}

int print_e(va_list ap, specifier_t spe)
{
    double nb = va_arg(ap, double);
    int count = 0;

    if (spe.prec == -1)
        spe.prec = 6;
    if (nb == 0.0){
        return my_putstr("0.000000e+00");
    }
    if (spe.space == 1)
        print_space(" ", nb);
    print_width(spe.width, &count, spe.prec + len_nb((int)nb) + 2);
    my_scient(nb, spe.prec - 1);
    return count;
}

int print_e_upper(va_list ap, specifier_t spe)
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
    my_scient_upper(nb, spe.prec - 1);
    return count;
}
