/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** initialize entities
*/

#include "../../include/my.h"
#include "../../include/window_csfml.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

float get_angle(plane_t *plane)
{
    float delta_x = plane->arrival.x - plane->departure.x;
    float delta_y = plane->arrival.y - plane->departure.y;
    float angle = atan(delta_y / delta_x);

    if (delta_x < 0)
        return angle * 180 / M_PI + 180;
    return angle * 180 / M_PI;
}

static void pars_data(entities_t *entities, char **data,
    int *i_plane, int *i_tower)
{
    if (data[0][0] == 'A'){
            entities->planes[*i_plane] = get_plane_data(data);
            *i_plane += 1;
        } else if (data[0][0] == 'T'){
            entities->towers[*i_tower] = get_tower_data(data);
            *i_tower += 1;
        }
}

static int get_data_entities(const char *script, entities_t *entities)
{
    FILE *file = fopen(script, "r");
    size_t n = 0;
    char *line = NULL;
    char **data = NULL;
    int i_plane = 0;
    int i_tower = 0;

    if (file == NULL)
        return 84;
    while (getline(&line, &n, file) != -1){
        data = my_str_to_word_array(line);
        pars_data(entities, data, &i_plane, &i_tower);
        free_word_array(data);
    }
    fclose(file);
    return 0;
}

static int get_nb_entities(const char *script, entities_t *entities)
{
    FILE *file = fopen(script, "r");
    size_t n = 0;
    char *line = NULL;
    char **data = NULL;

    if (file == NULL){
        write(2, "file doesn't exist\n", my_strlen("file doesn't exist\n"));
        return 84;
    }
    while (getline(&line, &n, file) != -1){
        data = my_str_to_word_array(line);
        if (data[0][0] == 'A')
            entities->nb_planes += 1;
        else
            entities->nb_towers += 1;
        free_word_array(data);
    }
    free(line);
    fclose(file);
    return 0;
}

entities_t *init_entities(const char *script)
{
    entities_t *entities = malloc(sizeof(entities_t));

    if (get_nb_entities(script, entities) == 84){
        free(entities);
        return NULL;
    }
    entities->planes = malloc(sizeof(plane_t) * entities->nb_planes);
    entities->towers = malloc(sizeof(tower_t) * entities->nb_towers);
    if (get_data_entities(script, entities) == 84){
        free(entities);
        return NULL;
    }
    return entities;
}
