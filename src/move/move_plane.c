/*
** EPITECH PROJECT, 2025
** move_plane
** File description:
** moving all planes
*/

#include "../../include/window_csfml.h"
#include <math.h>

static int is_arrived(plane_t *plane)
{
    float distance = sqrt(pow((plane->arrival.x) - (plane->position.x), 2) +
        pow((plane->arrival.y) - (plane->position.y), 2));
    sfVector2f out = {-500, -500};

    if (distance <= 20){
        sfSprite_setPosition(plane->img.sprite, out);
        return 1;
    }
    return 0;
}

static void in_tower(plane_t *plane, tower_t *towers, int nb_tower)
{
    int norm = 0;
    sfVector2f center = sfRectangleShape_getOrigin(plane->hitbox);

    center.x += plane->position.x - 20;
    center.y += plane->position.y - 20;
    for (int i = 0; i < nb_tower; i++){
        norm = sqrt(pow(center.x - towers[i].pos.x, 2) +
                    pow(center.y - towers[i].pos.y, 2));
        if (norm <= towers[i].radius + 10){
            plane->in_tower = 1;
            return;
        }
        plane->in_tower = 0;
    }
}

static void moving_planes(entities_t *entities, int index)
{
    in_tower(&entities->planes[index], entities->towers, entities->nb_towers);
    if (!is_arrived(&entities->planes[index]) &&
        is_flying(entities->planes[index]) &&
        entities->planes[index].delay == 0){
        sfSprite_move(entities->planes[index].img.sprite,
            get_move(entities->planes[index]));
        entities->planes[index].position =
            sfSprite_getPosition(entities->planes[index].img.sprite);
        sfRectangleShape_move(entities->planes[index].hitbox,
            get_move(entities->planes[index]));
    } else {
        entities->planes[index].delay -= ONE_SEC_IN_MS / MOVE_PER_SECOND;
    }
}

void mov_plane(entities_t *entities, sfClock *plane_clock)
{
    if (sfClock_getElapsedTime(plane_clock).microseconds >=
        ONE_SEC_IN_MS / MOVE_PER_SECOND){
        for (int i = 0; i < entities->nb_planes; i++){
            moving_planes(entities, i);
        }
        sfClock_restart(plane_clock);
    }
}
