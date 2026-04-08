/*
** EPITECH PROJECT, 2025
** my_printf_precision
** File description:
** A smaller version of printf
*/

#include "../../include/my.h"

int detect_width(const char *format, format_t *fmt)
{
    int index_from_i = *(fmt->i);
    int len_format = my_strlen(format);

    while (format[index_from_i] != '.' && index_from_i != len_format - 1) {
        if (format[index_from_i] >= '1' && format[index_from_i] <= '9') {
            return (index_from_i);
        }
        index_from_i++;
    }
    return (0);
}

int extract_width(const char *format, index_arguments_t *i_args)
{
    int index_width = i_args->i_width;
    int width = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * my_strlen(format));

    for (int j = index_width;
        format[j] && format[j] >= '0' && format[j] <= '9'; j++) {
        str[k] = format[j];
        k++;
    }
    str[k] = '\0';
    width = my_getnbr(my_strdup(str));
    free(str);
    return (width);
}

void process_width(arguments_t *args, format_t *fmt)
{
    char *tmp = malloc(sizeof(long long) + 1);
    char *tmp_str = fmt->str;
    char c = fmt->conv;

    if (args->conversion == 'n')
        return;
    if (fmt->is_hashtag_flag == 1 && (c == 'd' || c == 'i' || c == 'o' ||
            c == 'u' || c == 'x' || c == 'X'))
        args->width -= 2;
    for (int i = 0; i < args->width - my_strlen(fmt->str); i++) {
        if (fmt->is_zero_flag == 1 && !args->precision
            && fmt->is_minus_flag == 0) {
            tmp[i] = '0';
            continue;
        }
        tmp[i] = ' ';
    }
    fmt->str = (fmt->is_minus_flag == 0) ? my_strcat(my_strdup(tmp), tmp_str)
        : my_strcat(tmp_str, my_strdup(tmp));
    free(tmp);
}
