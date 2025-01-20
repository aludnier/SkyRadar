/*
** EPITECH PROJECT, 2024
** macro
** File description:
** csfml
*/

#include <stdbool.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>

#ifndef MY_RADAR
    #define MY_RADAR
    #define MAX_PLANE_QUAD 25

enum movement_per_second {
    MOVE_PER_SECOND = 100,
    ONE_SEC_IN_MS = 1000000
};

enum window_size {
    HEIGTH = 1080,
    WIDTH = 1920,
    BPS = 32
};

typedef struct image_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect area;
} image_t;

typedef struct plane_s {
    image_t img;
    sfVector2f position;
    sfIntRect area;
    sfRectangleShape *hitbox;
    sfVector2f departure;
    sfVector2f arrival;
    int speed;
    int delay;
    int in_tower;
} plane_t;

typedef struct tower_s {
    image_t img;
    sfVector2f pos;
    int radius;
    sfCircleShape *circle;
} tower_t;

typedef struct entities_s {
    int nb_planes;
    plane_t *planes;
    int nb_towers;
    tower_t *towers;
} entities_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfIntRect area;
    image_t background;
    entities_t entities;
    int draw_quad;
    int draw_hitbox;
} window_t;

typedef struct corner_s {
    sfIntRect area;
    unsigned int nb_planes;
    plane_t *planes;
}corner_t;

window_t *init_window(char *script);
int main_loop(char *script);
sfCircleShape *create_circle(sfVector2f position, float radius);
int is_intersecting_planes(plane_t *p1, plane_t *p2);
corner_t *init_corners(sfIntRect area, window_t wd, int nb_planes);
entities_t *init_entities(const char *script);
void draw_plane(window_t wd);
void draw_tower(window_t wd);
sfVector2f get_move(plane_t plane);
void destroy_window(window_t *wd);
void mov_plane(entities_t *entities, sfClock *plane_clock);
void quadtree(sfIntRect area, plane_t *planes, int nb_planes, window_t wd);
float get_angle(plane_t *);
plane_t get_plane_data(char **data);
tower_t get_tower_data(char **data);
void set_plane_img(plane_t *plane);
void set_tower_img(tower_t *tower);
int is_flying(plane_t plane);
void draw_bg(window_t wd);
void draw_entities(window_t wind);
void draw_quadtree(window_t wd, corner_t *corners);
void init_bg(window_t *wd);
int print_usage(void);

#endif
