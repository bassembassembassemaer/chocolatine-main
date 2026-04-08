/*
** EPITECH PROJECT, 2025
** my_srtlen
** File description:
** Write a function that counts and returns the number
** of characters found in the string passed as parameter.
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int len = 0;

    while (*str != '\0') {
        len++;
        str++;
    }
    return (len);
}
