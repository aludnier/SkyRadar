/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** draw background
*/

#include "../../include/window_csfml.h"

void draw_bg(window_t wd)
{
    sfRenderWindow_drawSprite(wd.window, wd.background.sprite, NULL);
}
