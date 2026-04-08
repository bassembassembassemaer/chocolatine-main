/*
** EPITECH PROJECT, 2025
** my_printf_conversions
** File description:
** A smaller version of printf
*/

#include "../../include/my.h"

static void verif_zero_zero(format_t *fmt)
{
    if ((fmt->precision == -1) && fmt->str[0] == '0')
        fmt->str = "";
    fmt->len = my_strlen(fmt->str);
}

static void d_i_conv(format_t *fmt)
{
    if (my_strcmp(fmt->len_modifier, "hh") == 0)
        fmt->str = putnbrs((char)va_arg(*(fmt->list), int));
    if (my_strcmp(fmt->len_modifier, "h") == 0)
        fmt->str = putnbrs((short)va_arg(*(fmt->list), int));
    if (my_strcmp(fmt->len_modifier, "ll") == 0)
        fmt->str = putnbrs(va_arg(*(fmt->list), long));
    if (my_strcmp(fmt->len_modifier, "l") == 0)
        fmt->str = putnbrs(va_arg(*(fmt->list), long long));
    if (my_strcmp(fmt->len_modifier, "j") == 0)
        fmt->str = putnbrs(va_arg(*(fmt->list), intmax_t));
    if (my_strcmp(fmt->len_modifier, "z") == 0)
        fmt->str = putnbrs(va_arg(*(fmt->list), size_t));
    if (my_strcmp(fmt->len_modifier, "t") == 0)
        fmt->str = putnbrs(va_arg(*(fmt->list), ptrdiff_t));
    if (my_strcmp(fmt->len_modifier, "") == 0)
        fmt->str = putnbrs(va_arg(*(fmt->list), int));
    verif_zero_zero(fmt);
}

static void o_conv(format_t *fmt)
{
    char *a = "0123456789";
    char *b = "01234567";
    va_list *l = fmt->list;

    fmt->str = convert_base(putnbrs(va_arg(*l, unsigned int)), a, b);
    if (my_strcmp(fmt->len_modifier, "hh") == 0)
        fmt->str = convert_base(putnbrs((char)va_arg(*l, unsigned int)), a, b);
    if (my_strcmp(fmt->len_modifier, "h") == 0)
        fmt->str = convert_base(putnbrs((short)va_arg(*l, unsigned int)), a, b);
    if (my_strcmp(fmt->len_modifier, "ll") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, unsigned long)), a, b);
    if (my_strcmp(fmt->len_modifier, "l") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, unsigned long long)), a, b);
    if (my_strcmp(fmt->len_modifier, "j") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, uintmax_t)), a, b);
    if (my_strcmp(fmt->len_modifier, "z") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, size_t)), a, b);
    if (my_strcmp(fmt->len_modifier, "t") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, ptrdiff_t)), a, b);
    verif_zero_zero(fmt);
}

static void u_conv(format_t *fmt)
{
    if (my_strcmp(fmt->len_modifier, "hh") == 0)
        fmt->str = putnbr_unsigned((char)va_arg(*(fmt->list), unsigned int));
    if (my_strcmp(fmt->len_modifier, "h") == 0)
        fmt->str = putnbr_unsigned((short)va_arg(*(fmt->list), unsigned int));
    if (my_strcmp(fmt->len_modifier, "ll") == 0)
        fmt->str = putnbr_unsigned(va_arg(*(fmt->list), unsigned long));
    if (my_strcmp(fmt->len_modifier, "l") == 0)
        fmt->str = putnbr_unsigned(va_arg(*(fmt->list), unsigned long long));
    if (my_strcmp(fmt->len_modifier, "j") == 0)
        fmt->str = putnbr_unsigned(va_arg(*(fmt->list), uintmax_t));
    if (my_strcmp(fmt->len_modifier, "z") == 0)
        fmt->str = putnbr_unsigned(va_arg(*(fmt->list), size_t));
    if (my_strcmp(fmt->len_modifier, "t") == 0)
        fmt->str = putnbr_unsigned(va_arg(*(fmt->list), ptrdiff_t));
    if (my_strcmp(fmt->len_modifier, "") == 0)
        fmt->str = putnbr_unsigned(va_arg(*(fmt->list), unsigned int));
    verif_zero_zero(fmt);
}

static void x_conv(format_t *fmt)
{
    char *a = "0123456789";
    char *b = "0123456789abcdef";
    va_list *l = fmt->list;

    fmt->str = convert_base(putnbrs(va_arg(*l, unsigned int)), a, b);
    if (my_strcmp(fmt->len_modifier, "hh") == 0)
        fmt->str = convert_base(putnbrs((char)va_arg(*l, unsigned int)), a, b);
    if (my_strcmp(fmt->len_modifier, "h") == 0)
        fmt->str = convert_base(putnbrs((short)va_arg(*l, unsigned int)), a, b);
    if (my_strcmp(fmt->len_modifier, "ll") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, unsigned long)), a, b);
    if (my_strcmp(fmt->len_modifier, "l") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, unsigned long long)), a, b);
    if (my_strcmp(fmt->len_modifier, "j") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, uintmax_t)), a, b);
    if (my_strcmp(fmt->len_modifier, "z") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, size_t)), a, b);
    if (my_strcmp(fmt->len_modifier, "t") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, ptrdiff_t)), a, b);
    verif_zero_zero(fmt);
}

static void xmaj_conv(format_t *fmt)
{
    char *a = "0123456789";
    char *b = "0123456789ABCDEF";
    va_list *l = fmt->list;

    fmt->str = convert_base(putnbrs(va_arg(*l, unsigned int)), a, b);
    if (my_strcmp(fmt->len_modifier, "hh") == 0)
        fmt->str = convert_base(putnbrs((char)va_arg(*l, unsigned int)), a, b);
    if (my_strcmp(fmt->len_modifier, "h") == 0)
        fmt->str = convert_base(putnbrs((short)va_arg(*l, unsigned int)), a, b);
    if (my_strcmp(fmt->len_modifier, "ll") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, unsigned long)), a, b);
    if (my_strcmp(fmt->len_modifier, "l") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, unsigned long long)), a, b);
    if (my_strcmp(fmt->len_modifier, "j") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, uintmax_t)), a, b);
    if (my_strcmp(fmt->len_modifier, "z") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, size_t)), a, b);
    if (my_strcmp(fmt->len_modifier, "t") == 0)
        fmt->str = convert_base(putnbrs(va_arg(*l, ptrdiff_t)), a, b);
    verif_zero_zero(fmt);
}

static void f_conv(format_t *fmt)
{
    double nb = va_arg(*(fmt->list), double);
    int ex = (fmt->precision > 0 || fmt->precision == -1) ? fmt->precision : 6;
    double fraction;
    long long chiffre;

    if (nb < 0)
        fmt->str = my_strcat(fmt->str, "-");
    nb = nb >= 0 ? nb + 0.5 / my_power(10, ex) : -(nb - 0.5 / my_power(10, ex));
    fraction = nb - (long long)nb;
    fmt->str = my_strcat(fmt->str, putnbrs((long long)nb));
    fmt->str = my_strcat(fmt->str, ".");
    for (int n = 0; n < ex; n++) {
        fraction *= 10 + my_power(10, -((ex >= 6) ? (ex) : (6)));
        chiffre = (long long)fraction;
        fraction -= chiffre;
        fmt->str = my_strcat(fmt->str, putnbrs(chiffre));
    }
    fmt->len = my_strlen(fmt->str);
}

static void s_conv(format_t *fmt)
{
    fmt->str = va_arg(*(fmt->list), char *);
    fmt->len += my_strlen(fmt->str);
}

static void c_conv(format_t *fmt)
{
    fmt->str[0] = va_arg(*(fmt->list), int);
    fmt->len += my_strlen(fmt->str);
}

void process_conversion(arguments_t *args, format_t *fmt)
{
    conversion_table_t c_table[] = {
        {'d', d_i_conv}, {'i', d_i_conv}, {'c', c_conv}, {'s', s_conv},
        {'u', u_conv}, {'x', x_conv}, {'X', xmaj_conv}, {'o', o_conv},
        {'f', f_conv}, {'F', f_conv}, {'n', n_conv}, {'e', e_conv},
        {'E', e_conv}, {'g', g_conv}, {'G', g_conv}, {'a', a_conv},
        {'A', a_conv}, {'p', p_conv}, {'%', percent_conv}, {0, NULL}
    };

    for (int i = 0; i < 19; i++) {
        if (args->conversion == c_table[i].conversion)
            c_table[i].func(fmt);
    }
    return;
}
