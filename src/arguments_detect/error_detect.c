/*
** EPITECH PROJECT, 2025
** my_printf_error_detect
** File description:
** A smaller version of printf
*/

#include "../../include/my.h"

static int error_flags(index_arguments_t *i_args)
{
    int flags = i_args->i_flags;

    if ((flags > i_args->i_precision && i_args->i_precision > 0) ||
        (flags > i_args->i_width && i_args->i_width > 0) ||
        (flags > i_args->i_len_modifier && i_args->i_len_modifier > 0))
        return (-1);
    return (0);
}

static int error_width(index_arguments_t *i_args)
{
    int width = i_args->i_width;

    if ((width > i_args->i_precision && i_args->i_precision > 0) ||
        (width < i_args->i_flags && i_args->i_flags > 0) ||
        (width > i_args->i_len_modifier && i_args->i_len_modifier > 0))
        return (-1);
    return (0);
}

static int error_precision(index_arguments_t *i_args)
{
    int pre = i_args->i_precision;

    if ((pre < i_args->i_flags && i_args->i_flags > 0) ||
        (pre < i_args->i_width && i_args->i_width > 0) ||
        (pre > i_args->i_len_modifier && i_args->i_len_modifier > 0))
        return (-1);
    return (0);
}

static int error_len_modifier(index_arguments_t *i_args)
{
    int l_modif = i_args->i_len_modifier;

    if ((l_modif < i_args->i_precision && i_args->i_precision > 0) ||
        (l_modif < i_args->i_width && i_args->i_width > 0) ||
        (l_modif < i_args->i_flags && i_args->i_flags > 0))
        return (-1);
    return (0);
}

static int separate_flags(const char *format, format_t *fmt, int i_conv)
{
    int seperation = 0;

    for (int j = *(fmt->i) + 1; j < i_conv; j++) {
        if (in_possible_flags(format[j]) != 1)
            seperation = 1;
        if (in_possible_flags(format[j]) == 1 && seperation != 0
            && (format[j] != '0'))
            return (-1);
    }
    return (0);
}

int error_detect(const char *format, index_arguments_t *i_args, format_t *fmt)
{
    if (!i_args->i_conversion)
        return (-1);
    if (i_args->i_flags > 0 && error_flags(i_args) == -1)
        return (-1);
    if (i_args->i_width > 0 && error_width(i_args) == -1)
        return (-1);
    if (i_args->i_precision > 0 && error_precision(i_args) == -1)
        return (-1);
    if (i_args->i_len_modifier > 0 && error_len_modifier(i_args) == -1)
        return (-1);
    if (i_args->i_flags > 0 && separate_flags(format, fmt,
            i_args->i_conversion) == -1)
        return (-1);
    return (0);
}
