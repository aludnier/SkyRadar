/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** initialize plane struct
*/

#include "../../include/window_csfml.h"
#include "../../include/my.h"
#include <stdlib.h>

static void create_hitbox(plane_t *plane)
{
    plane->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(plane->hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(plane->hitbox, (sfVector2f){10, 10});
    sfRectangleShape_setRotation(plane->hitbox, get_angle(plane));
    sfRectangleShape_setPosition(plane->hitbox, plane->position);
    sfRectangleShape_setFillColor(plane->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(plane->hitbox, sfGreen);
    sfRectangleShape_setOutlineThickness(plane->hitbox, 1);
}

plane_t get_plane_data(char **data)
{
    plane_t *plane = malloc(sizeof(struct plane_s));
    sfVector2f departure = {my_getnbr(data[1]), my_getnbr(data[2])};
    sfVector2f arrival = {my_getnbr(data[3]), my_getnbr(data[4])};

    plane->position = departure;
    plane->departure = departure;
    plane->arrival = arrival;
    plane->speed = my_getnbr(data[5]);
    plane->delay = my_getnbr(data[6]) * ONE_SEC_IN_MS;
    plane->in_tower = 1;
    create_hitbox(plane);
    set_plane_img(plane);
    return *plane;
}
