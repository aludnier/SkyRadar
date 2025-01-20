/*
** EPITECH PROJECT, 2024
** my_is_nbr
** File description:
** is char nbr
*/

int is_nbr(char c)
{
    if (c <= 57 && c >= 48){
        return (int) c - 48;
    }
    return -1;
}
