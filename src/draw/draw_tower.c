/*
** EPITECH PROJECT, 2025
** draw_tower
** File description:
** draw all tower
*/

#include "../../include/window_csfml.h"

void draw_tower(window_t wd)
{
    for (int i = 0; i < wd.entities.nb_towers; i++){
        sfRenderWindow_drawSprite(wd.window,
            wd.entities.towers[i].img.sprite, NULL);
        sfRenderWindow_drawCircleShape(wd.window,
            wd.entities.towers[i].circle, NULL);
    }
}
