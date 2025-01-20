/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** its an mini_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int search_flag(char params, va_list ap, char *specifier)
{
    flag_function_t f[20];
    int i = 0;
    int count = 0;
    specifier_t spe = init_specifier(specifier);

    init_tab_func(f);
    for (i = 0; f[i].c != '\0'; i++){
        if (params == f[i].c){
            count += f[i].func(ap, spe);
        }
    }
    free(specifier);
    return count;
}

int find_flag(const char *format, int *i, va_list ap)
{
    char flag[] = "cid%sxXofFEeaApung";
    int i_flag = 0;
    char *specifier = malloc(sizeof(char) * 20);
    int i_spe = *i;

    while (format[*i] != flag[i_flag]){
        i_flag++;
        if (flag[i_flag] == '\0'){
            i_flag = 0;
            specifier[*i - i_spe] = format[*i];
            *i += 1;
        }
    }
    return search_flag(format[*i], ap, specifier);
}

void check_n_flag(char param, va_list ap, int count)
{
    if (param == 'n'){
        *va_arg(ap, int *) = count;
    }
    return;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int count = 0;

    va_start(ap, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            check_n_flag(format[i], ap, count);
            count += find_flag(format, &i, ap);
        } else {
            count += my_putchar(format[i]);
        }
        i++;
    }
    va_end(ap);
    return count;
}
