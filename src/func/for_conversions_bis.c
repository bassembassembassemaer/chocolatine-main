/*
** EPITECH PROJECT, 2025
** my_printf_conversions_bis
** File description:
** A smaller version of printf
*/

#include "../../include/my.h"

static void a_conv_hexa(uint64_t sign, uint64_t mantissa, format_t *fmt)
{
    char *hexa_conv = malloc(128);
    uint8_t four_bits_blocs;

    hexa_conv[0] = '\0';
    if (sign == 1)
        fmt->str = my_strcat(fmt->str, "-");
    fmt->str = my_strcat(fmt->str, "0x1.");
    for (int i = 52 - 4; i >= 0; i -= 4) {
        four_bits_blocs = (mantissa >> i) & 0xF;
        hexa_conv = my_strcat(hexa_conv, convert_base(putnbrs(
                    (int)four_bits_blocs), "0123456789", "0123456789abcdef"));
    }
    fmt->str = my_strcat(fmt->str, delete_zeros(my_strdup(hexa_conv)));
    if (fmt->conv == 'a')
        fmt->str = my_strcat(fmt->str, "p+");
    else
        fmt->str = my_strcat(fmt->str, "P+");
    free(hexa_conv);
}

void a_conv(format_t *fmt)
{
    double nb = va_arg(*(fmt->list), double);
    union {
        double d;
        uint64_t u;
    } double_u;
    uint64_t bits;
    uint64_t exponent;
    uint64_t mantissa;

    double_u.d = nb;
    bits = double_u.u;
    exponent = ((bits >> 52) & 0x7FF) - 1023;
    mantissa = bits & ((1ULL << 52) - 1);
    a_conv_hexa(bits >> 63, mantissa, fmt);
    fmt->str = my_strcat(fmt->str, putnbrs((int)exponent));
    fmt->len = my_strlen(fmt->str);
}

void p_conv(format_t *fmt)
{
    void *ptr = va_arg(*(fmt->list), void *);
    unsigned long long addr = (unsigned long long)ptr;
    char *addr_hex = convert_base(putnbr_unsigned(addr), "0123456789",
        "0123456789abcdef");

    fmt->str = my_strcat(fmt->str, "0x");
    fmt->str = my_strcat(fmt->str, addr_hex);
    fmt->len = my_strlen(fmt->str);
}

void n_conv(format_t *fmt)
{
    int *ptr = va_arg(*(fmt->list), int *);

    *ptr = fmt->len;
    fmt->str = "";
    fmt->len = 0;
}

void percent_conv(format_t *fmt)
{
    fmt->str = "%";
    (fmt->len)++;
}
