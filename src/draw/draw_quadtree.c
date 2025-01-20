/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** draw quadtree
*/

#include "../../include/window_csfml.h"

void draw_quadtree(window_t wd, corner_t *corners)
{
    sfRectangleShape *quad = sfRectangleShape_create();

    for (int i = 0; i < 4; i++){
        sfRectangleShape_setPosition(quad,
            (sfVector2f){corners[i].area.left, corners[i].area.top});
        sfRectangleShape_setSize(quad,
            (sfVector2f){corners[i].area.width, corners[i].area.height});
        sfRectangleShape_setOutlineColor(quad, sfBlue);
        sfRectangleShape_setOutlineThickness(quad, 2);
        sfRectangleShape_setFillColor(quad, sfTransparent);
        sfRenderWindow_drawRectangleShape(wd.window, quad, NULL);
    }
    sfRectangleShape_destroy(quad);
}
