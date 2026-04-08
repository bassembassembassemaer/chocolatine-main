/*
** EPITECH PROJECT, 2025
** my_printf_conversions
** File description:
** tous les putnbr
*/

#include "../../include/my.h"

static int putnb_str(intmax_t nb, char *buff, int i)
{
    if (nb < 0) {
        buff[i] = '-';
        i++;
        nb = -nb;
    }
    if (nb >= 10)
        i = putnb_str(nb / 10, buff, i);
    buff[i] = (nb % 10) + '0';
    i++;
    return (i);
}

static int putnb_str_unsigned(uintmax_t nb, char *buff, int i)
{
    if (nb >= 10)
        i = putnb_str_unsigned(nb / 10, buff, i);
    buff[i] = (nb % 10) + '0';
    i++;
    return (i);
}

char *putnbrs(intmax_t nb)
{
    char buff[32];
    int len = putnb_str(nb, buff, 0);

    buff[len] = '\0';
    return my_strdup(buff);
}

char *putnbr_unsigned(uintmax_t nb)
{
    char buff[32];
    int len = putnb_str_unsigned(nb, buff, 0);

    buff[len] = '\0';
    return my_strdup(buff);
}
