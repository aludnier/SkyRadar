/*
** EPITECH PROJECT, 2024
** list malloc
** File description:
** list malloc
*/

#ifndef HEADER
    #define HEADER

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

linked_list_t *my_params_to_list(int ac, char *const *av);
void my_show_list(linked_list_t *list);

#endif
