/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** Concatenate a string src with an other one, dest. Return dest
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *out = malloc(dest_len + src_len + 1);

    for (int i = 0; i < dest_len; i++)
        out[i] = dest[i];
    for (int i = 0; i < src_len; i++)
        out[dest_len + i] = src[i];
    out[dest_len + src_len] = '\0';
    return (out);
}
