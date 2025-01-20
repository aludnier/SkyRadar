/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** set img for sprite
*/

#include "../../include/window_csfml.h"
#include "../../include/texture.h"
#include <stdio.h>

void init_bg(window_t *wd)
{
    wd->background.texture = sfTexture_createFromFile(TEXTURE_PATH[BG],
        &RECT_TEXTURE[BG]);
    wd->background.sprite = sfSprite_create();
    sfSprite_setTexture(wd->background.sprite, wd->background.texture,
        sfTrue);
    sfSprite_scale(wd->background.sprite, SCALE[BG]);
}

void set_plane_img(plane_t *plane)
{
    plane->img.texture = sfTexture_createFromFile(TEXTURE_PATH[PLANE],
        &RECT_TEXTURE[PLANE]);
    plane->img.sprite = sfSprite_create();
    sfSprite_setTexture(plane->img.sprite, plane->img.texture, sfTrue);
    sfSprite_setOrigin(plane->img.sprite, (sfVector2f){142, 134});
    sfSprite_setRotation(plane->img.sprite, get_angle(plane));
    sfSprite_scale(plane->img.sprite, SCALE[PLANE]);
    sfSprite_setPosition(plane->img.sprite, plane->departure);
    plane->img.area = sfSprite_getTextureRect(plane->img.sprite);
}

void set_tower_img(tower_t *tower)
{
    tower->img.texture = sfTexture_createFromFile(TEXTURE_PATH[TOWER],
        &RECT_TEXTURE[TOWER]);
    tower->img.sprite = sfSprite_create();
    sfSprite_setTexture(tower->img.sprite, tower->img.texture, sfTrue);
    sfSprite_scale(tower->img.sprite, SCALE[TOWER]);
    sfSprite_setPosition(tower->img.sprite, tower->pos);
}
