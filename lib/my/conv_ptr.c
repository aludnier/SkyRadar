/*
** EPITECH PROJECT, 2024
** conv_ptr
** File description:
** conv ptr to hex
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *conv_ptr(void *ptr)
{
    char *hexa = malloc(sizeof(char) * 20);
    char *ptr_conv = conv_to_hex((unsigned long) ptr);
    int index = 0;

    hexa[0] = '0';
    hexa[1] = 'x';
    while (ptr_conv[index] != '\0'){
        hexa[2 + index] = ptr_conv[index];
        index++;
    }
    return my_strlowcase(hexa);
}
