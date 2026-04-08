/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** Write a function that returns a number, sent to the function as a string.
*/

#include "../../include/my.h"

static int verif_int(char const *str, int i, int pos)
{
    if (pos == 1) {
        if (str[i] > '7' || str[i + 1] != '\0') {
            return (0);
        }
        return (1);
    }
    if (pos == -1) {
        if (str[i] > '8' || str[i + 1] != '\0') {
            return (0);
        }
        return (1);
    }
    return (0);
}

static int while_out(char const *str, int out, int i, int pos)
{
    int overflow_number = 1;

    while (str[i] >= '0' && str[i] <= '9') {
        if (out >= 214748364) {
            overflow_number = verif_int(str, i, pos);
        }
        if (overflow_number == 0) {
            return (0);
        }
        out = out * 10;
        out = (out + (str[i] - 48));
        i++;
    }
    if (pos == -1) {
        return (out * -1);
    }
    return (out);
}

static int pos_verif(char const *str, int *i)
{
    int sign = 1;

    while (str[*i] == ' ' || str[*i] == '+' || str[*i] == '-') {
        if (str[*i] == '-')
            sign = -sign;
        (*i)++;
    }
    if (str[*i] >= '0' && str[*i] <= '9') {
        return (sign);
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int out = 0;
    int pos;

    while (str[i] != '\0') {
        pos = pos_verif(str, &i);
        if (pos == 1 || pos == -1) {
            return (while_out(str, out, i, pos));
        }
        i++;
    }
    return (0);
}
