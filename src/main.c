/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** main
*/

#include "../include/window_csfml.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(int ac, char **av)
{
    if (ac != 2){
        write(2, "wrong arguments : try ./SkyRadar -h\n", 36);
        return 84;
    }
    if (!strcmp(av[1], "-h"))
        return print_usage();
    srand(time(NULL));
    return main_loop(av[1]);
}
