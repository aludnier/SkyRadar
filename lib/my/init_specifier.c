/*
** EPITECH PROJECT, 2024
** init_specifier
** File description:
** init spe stuct
*/

#include "my.h"
#include <stdio.h>
int get_precision(char *specifier, int *index)
{
    int nb = 0;

    while (is_nbr(specifier[*index + 1]) != -1){
        *index += 1;
        nb = nb * 10 + is_nbr(specifier[*index]);
    }
    *index += 1;
    return nb;
}

int get_width(char *specifier, int *index)
{
    int nb = 0;

    while (is_nbr(specifier[*index]) != -1){
        nb = nb * 10 + is_nbr(specifier[*index]);
        *index += 1;
    }
    return nb;
}

void check_len_mod(specifier_t *spe, int *index, char *specifier)
{
    if (specifier[*index] == 'l' && specifier[*index + 1] == 'l'){
        spe->is_long_double = 1;
        *index += 1;
        return;
    }
    if (specifier[*index] == 'h' && specifier[*index + 1] == 'h'){
        spe->is_char = 1;
        *index += 1;
        return;
    }
    if (specifier[*index] == 'h')
        spe->is_short = 1;
    if (specifier[*index] == 'l')
        spe->is_long = 1;
}

void check_specifier(specifier_t *spe, int *index, char *specifier)
{
    if (is_nbr(specifier[*index]) != -1)
        spe->width = get_width(specifier, index);
    if (specifier[*index] == '.')
        spe->prec = get_precision(specifier, index);
    if (specifier[*index] == '#')
        spe->alt = 1;
    if (specifier[*index] == ' ')
        spe->space = 1;
    if (specifier[*index] == '-')
        spe->left = 1;
    if (specifier[*index] == '+')
        spe->showsign = 1;
    if (specifier[*index] == '\'')
        spe->group = 1;
    check_len_mod(spe, index, specifier);
    return;
}

specifier_t init_specifier(char *specifier)
{
    specifier_t spe;
    int index = 0;

    spe.prec = -1;
    spe.width = -1;
    while (specifier[index] != '\0'){
        check_specifier(&spe, &index, specifier);
        index++;
    }
    return spe;
}
