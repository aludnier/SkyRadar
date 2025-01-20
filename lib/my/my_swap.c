/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** swap two int
*/
void my_swap(int *a, int *b)
{
    int change;

    change = *a;
    *a = *b;
    *b = change;
}
