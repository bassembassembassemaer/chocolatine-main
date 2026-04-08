/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** Write a function that allocates memory and copies
** the string given as argument in it.
*/

#include "../../include/my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));
    int i = 0;

    while (i < len) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
