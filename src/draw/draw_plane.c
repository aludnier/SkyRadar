/*
** EPITECH PROJECT, 2025
** draw_plane
** File description:
** set position and draw plane
*/

#include "../../include/window_csfml.h"
#include <math.h>
#include <stdio.h>

static void display_plane(window_t wd, plane_t plane)
{
    sfRenderWindow_drawSprite(wd.window, plane.img.sprite, NULL);
    if (plane.in_tower){
        sfRectangleShape_setOutlineColor(plane.hitbox, sfGreen);
    } else {
        sfRectangleShape_setOutlineColor(plane.hitbox, sfRed);
    }
    if (wd.draw_hitbox)
        sfRenderWindow_drawRectangleShape(wd.window, plane.hitbox, NULL);
}

void draw_plane(window_t wd)
{
    for (int i = 0; i < wd.entities.nb_planes; i++){
        if (is_flying(wd.entities.planes[i]) &&
            wd.entities.planes[i].delay == 0){
            display_plane(wd, wd.entities.planes[i]);
        }
    }
}
