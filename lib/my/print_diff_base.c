/*
** EPITECH PROJECT, 2024
** print_diffbase
** File description:
** print in differents base
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>
void prec_diff_base(specifier_t spe, int *count, int len)
{
    if (len > spe.prec)
        spe.prec = len;
    while (spe.prec - len > 0){
        count += my_putchar('0');
        spe.prec -= 1;
    }
}

int print_hexa(va_list ap, specifier_t spe)
{
    int count = 0;
    char *str = conv_to_hex(va_arg(ap, int));
    int len = my_strlen(str);

    print_width(spe.width, &count, spe.prec);
    prec_diff_base(spe, &count, len);
    count += my_putstr(str);
    return count;
}

int print_octa(va_list ap, specifier_t spe)
{
    int count = 0;
    char *str = conv_to_octa(va_arg(ap, int));
    int len = my_strlen(str);

    print_width(spe.width, &count, spe.prec);
    prec_diff_base(spe, &count, len);
    count += my_putstr(str);
    return count;
}

int print_hexa_low(va_list ap, specifier_t spe)
{
    int count = 0;
    char *str = conv_to_hex(va_arg(ap, int));
    int len = my_strlen(str);

    print_width(spe.width, &count, spe.prec);
    prec_diff_base(spe, &count, len);
    count += my_putstr(my_strlowcase(str));
    return count;
}

int print_ptr(va_list ap)
{
    int count = my_putstr(conv_ptr(va_arg(ap, void *)));

    return count;
}
