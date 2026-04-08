/*
** EPITECH PROJECT, 2025
** my_printf_conversions
** File description:
** A smaller version of printf
*/

#include "../../include/my.h"

int in_possible_flags(char c)
{
    const char *possible_flags = "+- 0#";
    int len_possible_flags = my_strlen(possible_flags);
    int i = 0;

    while (c != possible_flags[i]) {
        if (i == len_possible_flags - 1) {
            return (0);
        }
        i++;
    }
    return (1);
}

int detect_flags(const char *format, format_t *fmt)
{
    int index_from_i = *(fmt->i);

    while (in_possible_flags(format[index_from_i]) != 1
        || format[index_from_i] == '0') {
        if (format[index_from_i] == '+')
            fmt->is_plus_flag = 1;
        if (format[index_from_i] == fmt->conv) {
            index_from_i = 0;
            break;
        }
        index_from_i++;
    }
    if (in_possible_flags(format[*(fmt->i) + 1]) == 1)
        return (*(fmt->i) + 1);
    if (index_from_i != *(fmt->i))
        return (index_from_i);
    return (0);
}

char *extract_flags(const char *format, index_arguments_t *i_args)
{
    char *flags = malloc(sizeof(char) * my_strlen(format) + 1);
    char *out;
    int k = 0;
    int l = 0;

    if (i_args->i_flags == 0)
        return (NULL);
    while (in_possible_flags(format[i_args->i_flags + l]) == 1)
        l++;
    for (int j = i_args->i_flags; j < i_args->i_flags + l; j++) {
        flags[k] = format[j];
        k++;
    }
    flags[k] = '\0';
    out = my_strdup(flags);
    free(flags);
    return (out);
}
