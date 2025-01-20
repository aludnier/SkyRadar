/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** quadtree
*/

#include "../../include/window_csfml.h"
#include <stdlib.h>

static void in_wich_corner(plane_t plane, corner_t *corners)
{
    for (int i = 0; i < 4; i++){
        if (is_flying(plane) && plane.delay == 0 &&
            plane.position.x >= corners[i].area.left &&
            plane.position.x <= corners[i].area.left + corners[i].area.width &&
            plane.position.y >= corners[i].area.top &&
            plane.position.y <= corners[i].area.top + corners[i].area.height){
            corners[i].planes[corners[i].nb_planes] = plane;
            corners[i].nb_planes += 1;
        }
    }
}

static void check_collide(plane_t *arr, int nb_planes, int index)
{
    for (int i = 0; i < nb_planes; i++){
        if (i == index)
            continue;
        is_intersecting_planes(&arr[index], &arr[i]);
    }
}

static void collide_loop(plane_t *arr, int nb_planes)
{
    for (int i = 0; i < nb_planes; i++){
        check_collide(arr, nb_planes, i);
    }
}

void quadtree(sfIntRect area, plane_t *planes, int nb_planes, window_t wd)
{
    corner_t *corners = init_corners(area, wd, nb_planes);

    for (int i = 0; i < nb_planes; i++){
        in_wich_corner(planes[i], corners);
    }
    for (int i = 0; i < 4; i++){
        if (corners[i].planes == NULL){
            continue;
        }
        if (corners[i].nb_planes > MAX_PLANE_QUAD){
            quadtree(corners[i].area, corners[i].planes,
                corners[i].nb_planes, wd);
            continue;
        }
        collide_loop(corners[i].planes, corners[i].nb_planes);
    }
    for (int i = 0; i < 4; i++){
        free(corners[i].planes);
    }
    free(corners);
}
