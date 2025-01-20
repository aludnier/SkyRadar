/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** initialize corners
*/

#include "../../include/window_csfml.h"
#include <stdlib.h>
#include <stdio.h>

static corner_t create_corner(sfVector2f pos, int width,
    int heigth, int nb_planes)
{
    corner_t *corner = malloc(sizeof(corner_t));
    sfIntRect area = {pos.x, pos.y, width, heigth};
    plane_t *planes = malloc(sizeof(plane_t) * nb_planes);

    corner->area = area;
    corner->nb_planes = 0;
    corner->planes = planes;
    return *corner;
}

corner_t *init_corners(sfIntRect area, window_t wd, int nb_planes)
{
    int width = area.width / 2;
    int height = area.height / 2;
    corner_t *arr = malloc(sizeof(corner_t) * 5);

    arr[0] = create_corner((sfVector2f){area.left, area.top},
        width, height, nb_planes);
    arr[1] = create_corner((sfVector2f){area.left, area.top + height},
        width, height, nb_planes);
    arr[2] = create_corner((sfVector2f){area.left + width, area.top},
        width, height, nb_planes);
    arr[3] = create_corner((sfVector2f){area.left + width,
        area.top + height}, width, height, nb_planes);
    if (wd.draw_quad == 1)
        draw_quadtree(wd, arr);
    return arr;
}
