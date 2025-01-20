/*
** EPITECH PROJECT, 2025
** SkyRadar
** File description:
** print_usage
*/

#include <stdio.h>

int print_usage(void)
{
    printf("Fligth simulation\n");
    printf("Usage :\n\t./SkyRadar path-to-script\n\n");
    printf("Option :\n\t-h to show usage\n");
    printf("\t'R' key during simulation to show/hide Quadtree actions\n");
    printf("\t'H' key to show/hide plane's hitboxes\n");
    return 0;
}
