/*
** EPITECH PROJECT, 2025
** my_printf_conversions
** File description:
** A smaller version of printf
*/

#include "../../include/my.h"

static int all_char_possible(char c)
{
    const char *possible_char =
        "diuoxXfFsneEgGaAcp. +-#0hljztL123456789%";
    int len_possible_conversion = my_strlen(possible_char);
    int i = 0;

    while (c != possible_char[i]) {
        if (i == len_possible_conversion) {
            return (0);
        }
        i++;
    }
    return (1);
}

static int in_possible_conversion(char c)
{
    const char *possible_conversion = "diuoxXfFsneEgGaAcp%";
    int len_possible_conversion = my_strlen(possible_conversion);
    int i = 0;

    while (c != possible_conversion[i]) {
        if (i == len_possible_conversion) {
            return (0);
        }
        i++;
    }
    return (1);
}

int detect_conversion(const char *format, format_t *fmt)
{
    int index_from_i = *(fmt->i) + 1;
    int len_format = my_strlen(format);

    if (index_from_i == len_format)
        return (-1);
    while (in_possible_conversion(format[index_from_i]) != 1) {
        if (index_from_i == len_format)
            return (-1);
        index_from_i++;
    }
    for (int j = *(fmt->i) + 1; j < index_from_i; j++) {
        if (all_char_possible(format[j]) != 1)
            return (-1);
    }
    return (index_from_i);
}
