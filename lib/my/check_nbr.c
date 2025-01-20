/*
** EPITECH PROJECT, 2024
** check_nbr
** File description:
** verify if nbr or ltr
*/

int not_nbr_ltr(char c)
{
    if ((c > 96 && c < 123) || (c > 64 && c < 91)){
        return 0;
    }
    if (c < 58 && c > 47){
        return 0;
    }
    return 1;
}

int is_letter_or_number(char c)
{
    if ((c > 96 && c < 123) || (c > 64 && c < 91)){
        return 1;
    }
    if (c < 58 && c > 47){
        return 1;
    }
    return 0;
}
