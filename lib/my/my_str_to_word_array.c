/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** extract word from a str
*/
#include <stdlib.h>
#include "my.h"

int count_nb_word(char const *str)
{
    int nb_word = 0;
    int i = 0;

    if (is_letter_or_number(str[0]) == 1){
        nb_word++;
    }
    while (str[i] != 0){
        if (not_nbr_ltr(str[i]) == 1 && is_letter_or_number(str[i + 1]) == 1){
            nb_word++;
        }
        i++;
    }
    return nb_word;
}

static int increment_i_str(char const *str, int i_str)
{
    while (not_nbr_ltr(str[i_str]) && str[i_str] != '\0'){
        i_str += 1;
    }
    return i_str;
}

static void make_elements(char **arr, char const *str, int i_str, int index)
{
    int end_word = 0;
    int length = 0;

    while (is_letter_or_number(str[i_str]) || str[i_str] != '\0'){
        end_word = i_str;
        while (is_letter_or_number(str[end_word])){
            end_word++;
        }
        length = end_word - i_str;
        arr[index] = malloc(sizeof(char) * (length));
        while (i_str < end_word){
            arr[index][length - (end_word - i_str)] = str[i_str];
            i_str++;
        }
        i_str = increment_i_str(str, i_str);
        index++;
    }
}

char **my_str_to_word_array(char const *str)
{
    int i_str = 0;
    int index = 0;
    int nb_word = count_nb_word(str);
    char **arr = malloc(sizeof(char *) * nb_word + 1);

    while (not_nbr_ltr(str[i_str]) && str[i_str] != '\0'){
        i_str++;
    }
    make_elements(arr, str, i_str, index);
    arr[nb_word] = '\0';
    return arr;
}

void free_word_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++){
        free(arr[i]);
    }
    free(arr);
}

int len_chararr(char **arr)
{
    int len = 0;

    while (arr[len] != NULL){
        len++;
    }
    return len;
}
