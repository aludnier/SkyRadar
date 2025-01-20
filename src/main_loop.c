/*
** EPITECH PROJECT, 2024
** main window
** File description:
** my_radar
*/

#include "../include/window_csfml.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <math.h>
/*
void print_framerate ()
{
    static int first = 1;
    static sfClock * clock ;
    static int fps = 0;
    if ( first == 1)
        {
            clock = sfClock_create () ;
            first = 0;
        }
    sfTime elapsed = sfClock_getElapsedTime ( clock ) ;
    if ( sfTime_asSeconds ( elapsed ) >= 1)
        {
            printf("%3d FPS\n", fps ) ;
            fflush(stdout) ;
            fps = 0;
            sfClock_restart ( clock ) ;
        }
    else
        fps ++;
}*/

void handle_close(sfRenderWindow *wd, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wd);
}

void draw_option(window_t *wd, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR){
        if (wd->draw_quad)
            wd->draw_quad = 0;
        else
            wd->draw_quad = 1;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyH){
        if (wd->draw_hitbox)
            wd->draw_hitbox = 0;
        else
            wd->draw_hitbox = 1;
    }
}

void event_loop(window_t *wd)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(wd->window, &event)){
        handle_close(wd->window, event);
        draw_option(wd, event);
    }
}

int main_loop(char *script)
{
    window_t *wd = init_window(script);
    sfColor black = {0, 0, 0, 0};
    sfClock *plane_clock = sfClock_create();

    if (wd == NULL)
        return 84;
    while (sfRenderWindow_isOpen(wd->window)){
        event_loop(wd);
        mov_plane(&wd->entities, plane_clock);
        draw_bg(*wd);
        quadtree(wd->area, wd->entities.planes, wd->entities.nb_planes, *wd);
        draw_entities(*wd);
        sfRenderWindow_display(wd->window);
        sfRenderWindow_clear(wd->window, black);
    }
    destroy_window(wd);
    return 0;
}
