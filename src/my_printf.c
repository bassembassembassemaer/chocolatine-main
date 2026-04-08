/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** A smaller version of printf
*/

#include "../include/my.h"

static int safe_detect(int (*detect)(const char *, format_t *),
    const char *format, format_t *fmt, int conv)
{
    return (detect(format, fmt) < conv) ? detect(format, fmt) : 0;
}

static index_arguments_t index_args(const char *format, format_t *fmt)
{
    index_arguments_t index;

    index.i_conversion = detect_conversion(format, fmt);
    index.i_flags = safe_detect(detect_flags, format, fmt, index.i_conversion);
    index.i_width = safe_detect(detect_width, format, fmt, index.i_conversion);
    index.i_precision = safe_detect(detect_precision, format, fmt,
        index.i_conversion);
    index.i_len_modifier = safe_detect(detect_len_modifier, format, fmt,
        index.i_conversion);
    return (index);
}

static format_t format_init(va_list *list, int *i)
{
    format_t fmt;

    fmt.conv = '0';
    fmt.str = malloc(sizeof(char) * 1000);
    fmt.str[0] = '\0';
    fmt.precision = -2;
    fmt.list = list;
    fmt.i = i;
    fmt.is_zero_flag = 0;
    fmt.is_minus_flag = 0;
    fmt.is_hashtag_flag = 0;
    fmt.is_plus_flag = 0;
    return (fmt);
}

static arguments_t extract_args(const char *format, index_arguments_t *i_args,
    format_t *fmt)
{
    arguments_t args = {0};

    args.conversion = format[i_args->i_conversion];
    args.flags = extract_flags(format, i_args);
    args.len_modifier = extract_len_modifier(format, i_args);
    if (i_args->i_precision)
        args.precision = extract_precision(format, i_args, fmt);
    args.width = extract_width(format, i_args);
    return (args);
}

static void hashtag_flag(format_t *fmt)
{
    char *tmp = malloc(sizeof(long long) + 1);
    char const *tmp_str = fmt->str;

    if (fmt->conv == 'x' || fmt->conv == 'X') {
        tmp[0] = '0';
        if (fmt->conv == 'x')
            tmp[1] = 'x';
        if (fmt->conv == 'X')
            tmp[1] = 'X';
    }
    if (fmt->conv == 'o' && my_getnbr(fmt->str) != 0)
        tmp[0] = '0';
    if (tmp)
        fmt->str = my_strcat(tmp, tmp_str);
    free(tmp);
    return;
}

static int process_arguments(const char *format, format_t *fmt,
    arguments_t *args, index_arguments_t *i_args)
{
    if (error_detect(format, i_args, fmt) == -1)
        return (-1);
    process_conversion(args, fmt);
    if (args->flags && fmt->conv != '%')
        process_flags(args, fmt);
    if (args->precision && fmt->conv != '%')
        process_precision(args, fmt);
    if (args->width && fmt->conv != '%')
        process_width(args, fmt);
    if (fmt->is_hashtag_flag == 1 && fmt->conv != '%')
        hashtag_flag(fmt);
    my_putstr(fmt->str);
    free(fmt->str);
    return (0);
}

static int verif_zero_conv(int conv)
{
    if (conv == -1) {
        my_putchar('%');
        return 0;
    }
    return 1;
}

static void for_loop(const char *format, va_list *list, int *i, int *len_all)
{
    index_arguments_t i_args = {0};
    arguments_t args = {0};
    format_t fmt;

    if (format[*i] == '%') {
        fmt = format_init(list, i);
        i_args = index_args(format, &fmt);
        if (verif_zero_conv(i_args.i_conversion) == 0)
            return;
        args = extract_args(format, &i_args, &fmt);
        fmt.conv = args.conversion;
        fmt.len = *len_all;
        fmt.len_modifier = (args.len_modifier) ? args.len_modifier : "";
        if (process_arguments(format, &fmt, &args, &i_args) != -1) {
            (*i) += i_args.i_conversion - *i;
            return;
        }
    }
    my_putchar(format[*i]);
    (*len_all)++;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int len_all = 0;

    va_start(list, format);
    for (int i = 0; i < my_strlen(format); i++)
        for_loop(format, &list, &i, &len_all);
    va_end(list);
    return (len_all);
}

#include <stdio.h>
int main(void)
{
    printf("Hey %+d|\n", 42);
    my_printf("Hey %+d|\n", 42);
}
