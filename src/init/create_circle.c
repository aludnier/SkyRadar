/*
** EPITECH PROJECT, 2024
** create_circle
** File description:
** createa circle
*/

#include "../../include/window_csfml.h"

sfCircleShape *create_circle(sfVector2f coordinate, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f position = {coordinate.x + 10 - radius,
        coordinate.y + 10 - radius};

    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineColor(circle, sfYellow);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 2);
    return circle;
}
