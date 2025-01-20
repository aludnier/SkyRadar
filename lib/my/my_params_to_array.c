/*
** EPITECH PROJECT, 2024
** my_params_to_array
** File description:
** store parameters
*/
#include <stdlib.h>
#include "my.h"

struct info_param *my_param_to_array(int ac, char **av)
{
    int index = 0;
    struct info_param* parameter = malloc(sizeof(struct info_param) * ac + 1);

    for (index = 0; index < ac; index++){
        parameter[index].length = my_strlen(av[index]);
        parameter[index].str = av[index];
        parameter[index].copy = malloc(sizeof(char) * my_strlen(av[index]));
        my_strcpy(parameter[index].copy, av[index]);
        parameter[index].word_array = my_str_to_word_array(av[index]);
    }
    parameter[index].str = '\0';
    return parameter;
}
