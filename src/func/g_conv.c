/*
** EPITECH PROJECT, 2025
** my_printf_g_conv
** File description:
** A smaller version of printf
*/

#include "../../include/my.h"

char *delete_zeros(char *str)
{
    char *buff = str;
    int i = my_strlen(buff) - 1;

    while (i > 0 && (buff[i] == '0' || buff[i] == '.')) {
        if (buff[i] == '.') {
            buff[i] = '\0';
            break;
        }
        buff[i] = '\0';
        i--;
    }
    return (buff);
}

static int int_len_double(double nb)
{
    long long n = (nb < 0) ? -(long long)nb : (long long)nb;
    int len = 0;

    if (n == 0)
        return 1;
    while (n > 0) {
        n /= 10;
        len++;
    }
    return len;
}

static char *float_conv(double nb, int precision)
{
    int ex = precision;
    long long entier = (long long)nb;
    double fraction = nb - entier;
    long long chiffre;
    char *str = malloc(sizeof(intmax_t) + 1);

    str[0] = '\0';
    if (nb < 0)
        str = my_strcat(str, "-");
    str = my_strcat(str, putnbrs(entier));
    if (precision != 0)
        str = my_strcat(str, ".");
    for (int n = 0; n < ex; n++) {
        fraction *= 10 + my_power(10, -ex);
        chiffre = (long long)fraction;
        fraction -= chiffre;
        str = my_strcat(str, putnbrs(chiffre));
    }
    return (str);
}

static char *pos_e_conv(double nb, int dec, int conv)
{
    long n = 0;
    double chiffre = nb;
    char *str = malloc(sizeof(intmax_t) + 1);

    str[0] = '\0';
    while (chiffre >= 10.0) {
        chiffre /= 10.0;
        n++;
    }
    str = my_strcat(delete_zeros(float_conv(chiffre, dec)), "");
    if (conv == 'g')
        str = my_strcat(str, "e+");
    if (conv == 'G')
        str = my_strcat(str, "E+");
    if (n < 10) {
        str = my_strcat(str, "0");
        str = my_strcat(str, putnbrs(n));
    } else
        str = my_strcat(str, putnbrs(n));
    return (str);
}

static char *neg_e_conv(double nb, int dec, int conv)
{
    long n = 0;
    double chiffre = nb;
    char *str = malloc(sizeof(intmax_t) + 1);

    str[0] = '\0';
    while (chiffre < 1.0 && chiffre > 0) {
        chiffre *= 10.0;
        n++;
    }
    str = my_strcat(delete_zeros(float_conv(chiffre, dec)), "");
    if (conv == 'g')
        str = my_strcat(str, "e-");
    if (conv == 'G')
        str = my_strcat(str, "E-");
    if (n < 10) {
        str = my_strcat(str, "0");
        str = my_strcat(str, putnbrs(n));
    } else
        str = my_strcat(str, putnbrs(n));
    return (str);
}

static char *science_conv(double nb, int precision, int conv)
{
    int ex = precision;
    long long entier = (long long)nb;
    double fraction = nb - entier;
    char *str = malloc(sizeof(intmax_t) + 1);

    str[0] = '\0';
    if (nb < 0)
        str = my_strcat(str, "-");
    if ((long long)nb > 0 && ex >= 1) {
        nb = nb >= 0 ? nb + 0.5 / my_power(10, ex) :
            -(nb - 0.5 / my_power(10, ex));
        fraction = nb - (long long)nb;
        str = my_strcat(str, pos_e_conv(nb, fraction, conv));
    }
    if ((long long)nb == 0 && ex >= 1) {
        nb = nb >= 0 ? nb : -nb;
        fraction = nb - (long long)nb;
        str = my_strcat(str, neg_e_conv(nb, fraction, conv));
    }
    return (str);
}

static void select_version(format_t *fmt, double nb, int signif, int int_len)
{
    char *float_version = malloc(sizeof(intmax_t) + 1);
    char *science_version = malloc(sizeof(intmax_t) + 1);

    float_version[0] = '\0';
    science_version[0] = '\0';
    float_version = delete_zeros(float_conv(nb, (signif == 1) ? 5 : signif));
    science_version = science_conv(nb, (signif == 1) ? 5 : signif, fmt->conv);
    fmt->str = my_strdup((int_len > 7 || int_len <= -6)
        ? science_version : float_version);
    fmt->len = my_strlen(fmt->str);
    free(float_version);
    free(science_version);
}

void g_conv(format_t *fmt)
{
    double nb = va_arg(*(fmt->list), double);
    int ex = (fmt->precision > 1 || fmt->precision == -1) ? fmt->precision : 1;
    int int_len = (nb == 0) ? 1 : int_len_double(nb) + 1;
    int signif = (ex - int_len < 2) ? ex : (ex - int_len);

    if (nb < 0)
        fmt->str = my_strcat(fmt->str, "-");
    if ((long long)nb > 0)
        nb = nb >= 0 ? nb + 0.5 / my_power(10, ex) :
            -(nb - 0.5 / my_power(10, ex));
    else
        nb = nb >= 0 ? nb : -nb;
    select_version(fmt, nb, signif, int_len);
}
