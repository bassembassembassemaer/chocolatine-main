/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** Write a function that copies a string into another.
** The destination string will already have enough
** memory to copy the source string.
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int len = 0;

    while (src[len] != '\0') {
        dest[len] = src[len];
        len++;
    }
    dest[len] = '\0';
    return (dest);
}
