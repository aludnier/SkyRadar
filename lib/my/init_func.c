/*
** EPITECH PROJECT, 2024
** init_func
** File description:
** initialize function array
*/

#include "my.h"
#include <stdlib.h>

void add_to_struct(char c, function_t func, flag_function_t *arr, int index)
{
    flag_function_t add = {c, func};

    arr[index] = add;
}

void test(char *t)
{
    my_putchar(*t);
}

void init_tab_func(flag_function_t *f)
{
    add_to_struct('c', &print_char, f, 0);
    add_to_struct('i', &print_int, f, 1);
    add_to_struct('d', &print_int, f, 2);
    add_to_struct('%', &print_percent, f, 3);
    add_to_struct('s', &print_string, f, 4);
    add_to_struct('x', &print_hexa_low, f, 5);
    add_to_struct('X', &print_hexa, f, 6);
    add_to_struct('o', &print_octa, f, 7);
    add_to_struct('f', &print_float, f, 8);
    add_to_struct('F', &print_float, f, 9);
    add_to_struct('E', &print_e_upper, f, 10);
    add_to_struct('e', &print_e, f, 11);
    add_to_struct('a', &print_a_low, f, 12);
    add_to_struct('A', &print_a_upper, f, 13);
    add_to_struct('p', &print_ptr, f, 14);
    add_to_struct('u', &print_unsigned, f, 15);
    add_to_struct('g', &print_g, f, 16);
}
