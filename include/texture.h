/*
** EPITECH PROJECT, 2025
** macro
** File description:
** texture
*/


#ifndef TEXTURE
    #define TEXTURE
    #include <SFML/Graphics.h>

enum texture_index {
    PLANE = 0,
    TOWER = 1,
    BG = 2
};

const char *TEXTURE_PATH[] = {"./asset/plane.png",
    "./asset/tower2.png",
    "./asset/map.png"};

const sfIntRect RECT_TEXTURE[] = {{0, 0, 285, 268},
    {0, 0, 512, 512},
    {0, 0, 3780, 2520}};

const sfVector2f SCALE[] = {{1 / 14.25, 1 / 13.4},
    {1 / 25.0, 1 / 25.0},
    {(1920.0 / 3780), (1010.0 / 2520.0)}};

#endif
