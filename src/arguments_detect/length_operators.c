/*
** EPITECH PROJECT, 2025
** my_printf_length_operators
** File description:
** A smaller version of printf
*/

#include "../../include/my.h"

static int in_possible_len_modifier(char c)
{
    const char *possible_len_modifier = "hljztL";
    int i = 0;

    while (c != possible_len_modifier[i]) {
        if (i == 6) {
            return (0);
        }
        i++;
    }
    return (1);
}

int detect_len_modifier(const char *format, format_t *fmt)
{
    int index_from_i = *(fmt->i);
    int len_format = my_strlen(format);

    while (in_possible_len_modifier(format[index_from_i]) != 1) {
        if (index_from_i == len_format - 1) {
            return (0);
        }
        index_from_i++;
    }
    return (index_from_i);
}

char *extract_len_modifier(const char *format, index_arguments_t *i_args)
{
    int index_len_modifier = i_args->i_len_modifier;
    char *len_modifier = malloc(sizeof(char) * my_strlen(format) + 1);
    int k = 0;
    char *out;

    if (i_args->i_conversion - index_len_modifier > 2 ||
        index_len_modifier == 0)
        return (NULL);
    for (int j = index_len_modifier; j < i_args->i_conversion; j++) {
        len_modifier[k] = format[j];
        k++;
    }
    len_modifier[k] = '\0';
    if (i_args->i_conversion - index_len_modifier == 2 &&
        (my_strcmp(len_modifier, "hh") != 0
            && my_strcmp(len_modifier, "ll") != 0))
        return (NULL);
    out = my_strdup(len_modifier);
    free(len_modifier);
    return (out);
}
