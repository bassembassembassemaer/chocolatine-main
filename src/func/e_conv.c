/*
** EPITECH PROJECT, 2025
** my_printf_e_conv
** File description:
** A smaller version of printf
*/

#include "../../include/my.h"

static char *float_conv(double nb, int precision)
{
    int ex = precision;
    long long entier = (long long)nb;
    double fraction = nb - entier;
    long long chiffre;
    char *str = malloc(sizeof(intmax_t) + 1);

    if (nb < 0)
        str = my_strcat(str, "-");
    str = my_strcat(str, putnbrs(entier));
    str = my_strcat(str, ".");
    for (int n = 0; n < ex; n++) {
        fraction *= 10 + my_power(10, -ex);
        chiffre = (long long)fraction;
        fraction -= chiffre;
        str = my_strcat(str, putnbrs(chiffre));
    }
    return (str);
}

static void pos_e_conv(double nb, int dec, format_t *fmt)
{
    long n = 0;
    double chiffre = nb;

    while (chiffre >= 10.0) {
        chiffre /= 10.0;
        n++;
    }
    fmt->str = my_strcat(float_conv(chiffre, dec), "");
    if (fmt->conv == 'e')
        fmt->str = my_strcat(fmt->str, "e+");
    if (fmt->conv == 'E')
        fmt->str = my_strcat(fmt->str, "E+");
    if (n < 10) {
        fmt->str = my_strcat(fmt->str, "0");
        fmt->str = my_strcat(fmt->str, putnbrs(n));
    } else
        fmt->str = my_strcat(fmt->str, putnbrs(n));
}

static void neg_e_conv(double nb, int dec, format_t *fmt)
{
    long n = 0;
    double chiffre = nb;

    while (chiffre < 1.0 && chiffre > 0) {
        chiffre *= 10.0;
        n++;
    }
    fmt->str = my_strcat(float_conv(chiffre, dec), "");
    if (fmt->conv == 'e')
        fmt->str = my_strcat(fmt->str, "e-");
    if (fmt->conv == 'E')
        fmt->str = my_strcat(fmt->str, "E-");
    if (n < 10) {
        fmt->str = my_strcat(fmt->str, "0");
        fmt->str = my_strcat(fmt->str, putnbrs(n));
    } else
        fmt->str = my_strcat(fmt->str, putnbrs(n));
}

void e_conv(format_t *fmt)
{
    double nb = va_arg(*(fmt->list), double);
    int ex = (fmt->precision > 6 || fmt->precision == -1) ? fmt->precision : 6;
    double fraction;

    if (nb < 0)
        fmt->str = my_strcat(fmt->str, "-");
    if ((long long)nb > 0 && ex >= 6) {
        nb = nb >= 0 ? nb + 0.5 / my_power(10, ex) :
            -(nb - 0.5 / my_power(10, ex));
        fraction = nb - (long long)nb;
        pos_e_conv(nb, fraction, fmt);
    }
    if ((long long)nb == 0 && ex >= 6) {
        nb = nb >= 0 ? nb : -nb;
        fraction = nb - (long long)nb;
        neg_e_conv(nb, fraction, fmt);
    }
    fmt->len = my_strlen(fmt->str);
}
