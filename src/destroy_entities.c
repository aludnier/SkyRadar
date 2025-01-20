/*
** EPITECH PROJECT, 2025
** destroy_entities
** File description:
** free everything
*/

#include "../include/window_csfml.h"
#include <stdlib.h>

static void destroy_towers(entities_t entities)
{
    for (int i = 0; i < entities.nb_towers; i++){
        sfSprite_destroy(entities.towers[i].img.sprite);
        sfTexture_destroy(entities.towers[i].img.texture);
        sfCircleShape_destroy(entities.towers[i].circle);
    }
    free(entities.towers);
}

static void destroy_planes(entities_t entities)
{
    for (int i = 0; i < entities.nb_planes; i++){
        sfSprite_destroy(entities.planes[i].img.sprite);
        sfTexture_destroy(entities.planes[i].img.texture);
        sfRectangleShape_destroy(entities.planes[i].hitbox);
    }
    free(entities.planes);
}

void destroy_window(window_t *wd)
{
    destroy_planes(wd->entities);
    destroy_towers(wd->entities);
    sfRenderWindow_destroy(wd->window);
    free(wd);
}
