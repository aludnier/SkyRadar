/*
** EPITECH PROJECT, 2025
** ler.c
** File description:
** linear interpolation
*/

#include "../../include/window_csfml.h"
#include <math.h>

sfVector2f get_move(plane_t plane)
{
    float mx = plane.arrival.x - plane.position.x;
    float my = plane.arrival.y - plane.position.y;
    float movx = mx / sqrt(pow(mx, 2) + pow(my, 2));
    float movy = my / sqrt(pow(mx, 2) + pow(my, 2));
    sfVector2f move = {movx / plane.speed * MOVE_PER_SECOND,
        movy / plane.speed * MOVE_PER_SECOND};

    return move;
}
