/*
** EPITECH PROJECT, 2024
** conv_to_octal
** File description:
** conv to octal
*/

#include <stdlib.h>
#include "my.h"

char *conv_to_octa(int nb)
{
    char *octa = malloc(sizeof(char) * nb);
    int conv = 0;
    int i = 0;

    while (nb > 0){
        if (nb % 8 < 8){
            conv = nb % 8 + 48;
        } else {
            conv = nb % 8 + 57;
        }
        octa[i] = conv;
        i++;
        nb /= 8;
    }
    return my_revstr(octa);
}
