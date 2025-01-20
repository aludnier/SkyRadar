/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** check if plane is dead
*/

#include "../include/window_csfml.h"

int is_flying(plane_t plane)
{
    if (plane.position.x >= 0 && plane.position.y >= 0)
        return 1;
    return 0;
}
