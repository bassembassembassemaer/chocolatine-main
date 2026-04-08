/*
** EPITECH PROJECT, 2025
** my_printf_width
** File description:
** A smaller version of printf
*/

#include "../../include/my.h"

int detect_precision(const char *format, format_t *fmt)
{
    int index_from_i = *(fmt->i);
    int len_format = my_strlen(format);

    while (format[index_from_i] != '.') {
        if (index_from_i == len_format - 1) {
            return (0);
        }
        index_from_i++;
    }
    if (index_from_i != *(fmt->i)) {
        return (index_from_i);
    } else {
        return (0);
    }
}

int extract_precision(const char *format, index_arguments_t *i_args,
    format_t *fmt)
{
    int index_precision = i_args->i_precision;
    int precision = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * my_strlen(format));

    if (index_precision + 1 == i_args->i_conversion ||
        index_precision + 1 == i_args->i_len_modifier ||
        format[index_precision + 1] == '0')
        fmt->precision = -1;
    for (int j = index_precision + 1;
        format[j] && format[j] >= '0' && format[j] <= '9'; j++) {
        str[k] = format[j];
        k++;
    }
    str[k] = '\0';
    precision = my_getnbr(my_strdup(str));
    free(str);
    fmt->precision = (precision > 0) ? (precision) : (fmt->precision);
    return (precision);
}

static int plus_minus_handler(format_t *fmt, char c, char *tmp, char *tmp_str)
{
    int i = 0;
    int start = 0;

    if (fmt->str[0] == c) {
        while (tmp_str[i]) {
            tmp_str[i] = tmp_str[i + 1];
            i++;
        }
        tmp[0] = c;
        start = 1;
    }
    return (start);
}

static void precision_int(arguments_t *args, format_t *fmt)
{
    char *tmp = malloc(sizeof(long long) + 1);
    char *tmp_str = fmt->str;
    int strt = 0;
    int res;

    res = plus_minus_handler(fmt, '+', tmp, tmp_str);
    strt = (res > 0) ? (res) : (strt);
    res = plus_minus_handler(fmt, '-', tmp, tmp_str);
    strt = (res > 0) ? (res) : (strt);
    res = plus_minus_handler(fmt, ' ', tmp, tmp_str);
    strt = (res > 0) ? (res) : (strt);
    for (int i = strt; i < args->precision - my_strlen(fmt->str) + strt; i++) {
        tmp[i] = '0';
    }
    fmt->str = my_strcat(my_strdup(tmp), tmp_str);
    free(tmp);
    if (my_strcmp(fmt->str, "0") == 0) {
        fmt->str = "";
        return;
    }
}

static void precision_string(arguments_t *args, format_t *fmt)
{
    char *tmp = malloc(sizeof(long long) + 1);
    int j = 0;

    while (j < args->precision) {
        tmp[j] = fmt->str[j];
        j++;
    }
    tmp[j] = '\0';
    fmt->str = my_strdup(tmp);
    free(tmp);
    return;
}

void process_precision(arguments_t *args, format_t *fmt)
{
    char c = fmt->conv;

    if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X')
        precision_int(args, fmt);
    if (c == 's')
        precision_string(args, fmt);
    return;
}
