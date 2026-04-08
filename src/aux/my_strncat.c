/*
** EPITECH PROJECT, 2025
** my_strncat
** File description:
** Concatenate n char of a string src with an other one, dest. Return dest
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    int i = 0;

    while (i <= src_len && i < nb) {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}
