/*
** EPITECH PROJECT, 2024
** check_intersection
** File description:
** check intersect of two cicle
*/

#include "../../include/window_csfml.h"
#include <math.h>
#include <stdio.h>
#include <SFML/Graphics.h>

int plane_collide(plane_t *p1, plane_t *p2)
{
    if (sqrt(pow(p1->position.x - p2->position.x, 2)) < 20 &&
        sqrt(pow(p1->position.y - p2->position.y, 2)) < 20){
            return 1;
    }
    return 0;
}

int is_intersecting_planes(plane_t *p1, plane_t *p2)
{
    sfVector2f out_window = {-500, -500};

    if (plane_collide(p1, p2) &&
        !p1->in_tower && !p2->in_tower && is_flying(*p1) && is_flying(*p2)){
        sfSprite_setPosition(p1->img.sprite, out_window);
        sfSprite_setPosition(p2->img.sprite, out_window);
        sfRectangleShape_setPosition(p1->hitbox, out_window);
        sfRectangleShape_setPosition(p2->hitbox, out_window);
        return 1;
    }
    return 0;
}
