/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** length of a stt
*/
int my_strlen(char const *str)
{
    int i;
    int d;

    d = str[0];
    i = 0;
    while (d != '\0'){
        i++;
        d = str[i];
    }
    return i;
}
