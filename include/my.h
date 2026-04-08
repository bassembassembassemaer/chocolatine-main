/*
** EPITECH PROJECT, 2025
** my_strstr
** File description:
** Header file for my_strstr and helpers
*/

#ifndef MY_H
    #define MY_H
    #define NEW_LIGNE my_putchar('\n')
    #define ABS(value) (((value) < 0) ? ((value) * -1) : (value))
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <limits.h>

// === TYPEDEFS ===
    // Arguments stock
typedef struct arguments_s{
    char conversion;
    int precision;
    int width;
    char *len_modifier;
    char *flags;
} arguments_t;

typedef struct index_arguments_s{
    int i_conversion;
    int i_precision;
    int i_width;
    int i_len_modifier;
    int i_flags;
} index_arguments_t;

    // Format buffer
typedef struct format_s {
    char *str;
    int len;
    char conv;
    int precision;
    va_list *list;
    int *i;
    int is_zero_flag;
    int is_plus_flag;
    int is_minus_flag;
    int is_hashtag_flag;
    char *len_modifier;
} format_t;

    // Arguments function pointers
typedef struct conversion_table_s{
    char conversion;
    void (*func)(format_t *fmt);
} conversion_table_t;

typedef struct len_modifier_table_s{
    char *lm;
    void (*func)(format_t *fmt);
} len_modifier_table_t;

typedef struct flags_table_s{
    char flags;
    void (*func)(format_t *fmt);
} flags_table_t;

// === AUX FUNCTIONS ===
char *my_strcpy(char *dest, char const *src);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
char *delete_zeros(char *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_power(long long nb, int p);
double my_power_double(double nb, int p);
void my_putchar(char c);

// === ARGUMENTS DETECTION ===
    // Extraction
char *extract_flags(const char *format, index_arguments_t *i_args);
char *extract_len_modifier(const char *format, index_arguments_t *i_args);
int extract_width(const char *format, index_arguments_t *i_args);
int extract_precision(const char *format, index_arguments_t *i_args,
    format_t *fmt);

    // Index detection
int detect_conversion(const char *format, format_t *fmt);
int detect_flags(const char *format, format_t *fmt);
int detect_len_modifier(const char *format, format_t *fmt);
int detect_width(const char *format, format_t *fmt);
int detect_precision(const char *format, format_t *fmt);

    // Process
void process_flags(arguments_t *args, format_t *fmt);
void process_modifier(arguments_t *args, format_t *fmt);
void process_precision(arguments_t *args, format_t *fmt);
void process_width(arguments_t *args, format_t *fmt);
void process_conversion(arguments_t *args, format_t *fmt);

    // Else
int in_possible_flags(char c);

// === FUNCTIONS ===
    // Putnbr
char *putnbrs(intmax_t nb);
char *putnbr_unsigned(uintmax_t nb);

// === MAIN ===
int my_printf(const char *format, ...);
int error_detect(const char *format, index_arguments_t *i_args, format_t *fmt);

// == CONV BIS ===
void a_conv(format_t *fmt);
void p_conv(format_t *fmt);
void n_conv(format_t *fmt);
void e_conv(format_t *fmt);
void g_conv(format_t *fmt);
void percent_conv(format_t *fmt);

#endif /* !!!!MY_H */
