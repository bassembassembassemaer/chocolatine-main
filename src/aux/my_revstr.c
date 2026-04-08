/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** Write a function that reverses a string
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int compteur = 0;
    int i = 0;
    char switcher;
    int digit_switch;

    while (str[i] != '\0') {
        compteur++;
        i++;
    }
    i = 0;
    while (i != compteur / 2) {
        digit_switch = compteur - i - 1;
        switcher = str[i];
        str[i] = str[digit_switch];
        str[digit_switch] = switcher;
        i++;
    }
    return (str);
}
