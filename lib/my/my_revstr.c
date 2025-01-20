/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** reverse an string
*/
#include <unistd.h>

int my_strpaslen(char const *str)
{
    int counter = 0;

    while (str[counter] != '\0') {
        counter++;
    }
    return counter;
}

char *my_revstr(char *str)
{
    int size = my_strpaslen(str);
    int i;
    char T;
    char *first;
    char *last;

    for (i = 0; i < size / 2; i++) {
        first = &str[i];
        last = &str[size - i - 1];
        T = *first;
        *first = *last;
        *last = T;
        }
    return str;
}
