/*
** EPITECH PROJECT, 2025
** convert_base
** File description:
** Write a function that returns the result from the nbr string conversion
** (expressed in a base_from radix to a base_to radix), in the form of a newly,
** and sufficiently, allocated string. The number, represented by nbr,
** fits in an integer
*/

#include "../../include/my.h"

static int get_index(char const *base, char c)
{
    int i = 0;

    while (base[i] != c && base[i] != '\0')
        ++i;
    return i;
}

static void sign_detect(char const *nbr, int *sign, int *start)
{
    *sign = 1;
    *start = 0;
    if (nbr[0] == '-') {
        *sign = -1;
        *start = 1;
    } else if (nbr[0] == '+')
        *start = 1;
}

static char *horner_method(char const *nbr, char const *b1, char const *b2,
    int start)
{
    long long acc = 0;
    int len_nbr = my_strlen(nbr);
    int b_from = my_strlen(b1);
    int b_to = my_strlen(b2);
    char *result = malloc(sizeof(char) * 65);
    int i = 0;

    for (int i = start; i < len_nbr; i++)
        acc = acc * b_from + get_index(b1, nbr[i]);
    if (acc == 0) {
        result[i] = b2[0];
        i++;
    }
    while (acc > 0) {
        result[i] = b2[acc % b_to];
        acc = acc / b_to;
        i++;
    }
    result[i] = '\0';
    return (result);
}

static char *add_sign(char *result)
{
    int len = my_strlen(result);
    char *final = malloc(len + 2);

    final[0] = '-';
    for (int i = 0; i <= len; i++)
        final[i + 1] = result[i];
    free(result);
    return final;
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    int len_nbr = my_strlen(nbr);
    int b_from = my_strlen(base_from);
    int b_to = my_strlen(base_to);
    int sign;
    int start;
    char *result;

    if (len_nbr == 0 || b_from < 2 || b_to < 2)
        return (NULL);
    sign_detect(nbr, &sign, &start);
    result = horner_method(nbr, base_from, base_to, start);
    my_revstr(result);
    if (sign == -1)
        return (add_sign(result));
    return (result);
}
