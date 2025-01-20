/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** initialize tower
*/

#include "../../include/window_csfml.h"
#include "../../include/my.h"
#include <stdlib.h>

tower_t get_tower_data(char **data)
{
    tower_t *tower = malloc(sizeof(struct tower_s));
    sfVector2f position = {my_getnbr(data[1]), my_getnbr(data[2])};

    tower->pos = position;
    tower->radius = my_getnbr(data[3]);
    tower->circle = create_circle(position, tower->radius);
    set_tower_img(tower);
    return *tower;
}
