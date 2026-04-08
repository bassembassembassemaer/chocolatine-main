/*
** EPITECH PROJECT, 2025
** my_printf_flags
** File description:
** A smaller version of printf
*/

#include "../../include/my.h"

static void plus_flag(format_t *fmt)
{
    char c = fmt->conv;

    if (my_getnbr(fmt->str) < 0 && (fmt->conv == 'd' || fmt->conv == 'i'))
        return;
    if (c == 'd' || c == 'i' || c == 'u' || c == 'f' || c == 'F' || c == 'e' ||
        c == 'E' || c == 'g' || c == 'G')
        fmt->str = my_strcat("+", fmt->str);
}

static void space_flag(format_t *fmt)
{
    if (my_getnbr(fmt->str) < 0 && (fmt->conv == 'd' || fmt->conv == 'i'))
        return;
    if (!fmt->is_zero_flag && !fmt->is_plus_flag &&
        (fmt->conv == 'd' || fmt->conv == 'i' || fmt->conv == 'f' ||
            fmt->conv == 'E' || fmt->conv == 'e' || fmt->conv == 'G' ||
            fmt->conv == 'g'))
        fmt->str = my_strcat(" ", fmt->str);
}

static void minus_flag(format_t *fmt)
{
    fmt->is_minus_flag = 1;
}

static void zero_flag(format_t *fmt)
{
    fmt->is_zero_flag = 1;
}

static void hashtag_flag(format_t *fmt)
{
    fmt->is_hashtag_flag = 1;
}

void process_flags(arguments_t *args, format_t *fmt)
{
    flags_table_t flags_table[] = {
        {'+', plus_flag}, {'-', minus_flag}, {' ', space_flag},
        {'0', zero_flag}, {'#', hashtag_flag}, {0, NULL}
    };
    int len_flags = my_strlen(args->flags);
    int i = 0;

    for (int j = 0; j < len_flags; j++) {
        i = 0;
        while (i < 6 && args->flags[j] != flags_table[i].flags) {
            i++;
        }
        if (i < 6) {
            flags_table[i].func(fmt);
        }
    }
}
