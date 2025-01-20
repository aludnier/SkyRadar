/*
** EPITECH PROJECT, 2024
** init
** File description:
** initialize window
*/

#include "../../include/window_csfml.h"
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <stdlib.h>

window_t *init_window(char *script)
{
    window_t *wd = malloc(sizeof(struct window_s));
    sfVideoMode v_mode = {WIDTH, HEIGTH, BPS};
    sfIntRect area = {0, 0, WIDTH, HEIGTH};
    entities_t *entities = init_entities(script);

    if (entities == NULL){
        return NULL;
    }
    wd->window = sfRenderWindow_create(v_mode,
        "my_radar", sfDefaultStyle, NULL);
    wd->area = area;
    init_bg(wd);
    wd->entities = *entities;
    wd->draw_quad = 0;
    sfRenderWindow_setFramerateLimit(wd->window, 60);
    return wd;
}
