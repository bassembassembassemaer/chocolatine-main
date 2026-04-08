#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// === EASY TESTS ===
Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, empty_string, .init = redirect_all_std)
{
    my_printf("");
    cr_assert_stdout_eq_str("");
}

Test(my_printf, spaces, .init = redirect_all_std)
{
    my_printf("   spaced   ");
    cr_assert_stdout_eq_str("   spaced   ");
}

// === CHARS ===
Test(my_printf, single_char, .init = redirect_all_std)
{
    my_printf("%c", 'A');
    cr_assert_stdout_eq_str("A");
}

Test(my_printf, multiple_chars, .init = redirect_all_std)
{
    my_printf("%c %c %c", 'A', 'B', 'C');
    cr_assert_stdout_eq_str("A B C");
}

Test(my_printf, multiple_chars_with_prec_and_width, .init = redirect_all_std)
{
    my_printf("%.3c %4c %4.3c\n", 'A', 'B', 'C');
    cr_assert_stdout_eq_str("A    B    C\n");
}

Test(my_printf, char_with_unused_params_and_flags, .init = redirect_all_std)
{
    my_printf("%+0 #-3.4hca\n", 'A', 'B', 'C');
    cr_assert_stdout_eq_str("A  a\n");
}

// === STRINGS ===
Test(my_printf, simple_string_flag, .init = redirect_all_std)
{
    my_printf("%s", "Hello");
    cr_assert_stdout_eq_str("Hello");
}

Test(my_printf, string_with_spaces, .init = redirect_all_std)
{
    my_printf("Hello %s !", "World");
    cr_assert_stdout_eq_str("Hello World !");
}

Test(my_printf, string_with_prec, .init = redirect_all_std)
{
    my_printf("Hello %.3s !", "World");
    cr_assert_stdout_eq_str("Hello Wor !");
}

Test(my_printf, string_with_width, .init = redirect_all_std)
{
    my_printf("Hello %-5.3s !", "World");
    cr_assert_stdout_eq_str("Hello Wor   !");
}

Test(my_printf, string_with_flags, .init = redirect_all_std)
{
    my_printf("Hello %+0#-5.3hhs !", "World");
    cr_assert_stdout_eq_str("Hello Wor   !");
}

// === DECIMALS AND INTEGERS ===
Test(my_printf, positive_int, .init = redirect_all_std)
{
    my_printf("%d", 42);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf, negative_int, .init = redirect_all_std)
{
    my_printf("%d", -42);
    cr_assert_stdout_eq_str("-42");
}

Test(my_printf, zero_int, .init = redirect_all_std)
{
    my_printf("%d", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, multiple_ints, .init = redirect_all_std)
{
    my_printf("%d %i %d", 1, 2, 3);
    cr_assert_stdout_eq_str("1 2 3");
}

Test(my_printf, multiple_ints_with_prec_and_width, .init = redirect_all_std)
{
    my_printf("%.4d %4i %4.5d", 1, 2, 3);
    cr_assert_stdout_eq_str("0001    2 00003");
}

Test(my_printf, multiple_ints_len_modifs, .init = redirect_all_std)
{
    my_printf("%+d %hi %hhd", 1, (short)2, (signed char)130);
    cr_assert_stdout_eq_str("+1 2 -126");
}

// === PERCENT ESCAPE ===
Test(my_printf, percent_escape, .init = redirect_all_std)
{
    my_printf("100%% done");
    cr_assert_stdout_eq_str("100% done");
}

Test(my_printf, multiple_percent, .init = redirect_all_std)
{
    my_printf("%%%%");
    cr_assert_stdout_eq_str("%%");
}

// === MIXED TYPES ===
Test(my_printf, mixed_types, .init = redirect_all_std)
{
    my_printf("Char: %c, Str: %s, Int: %d%%", 'V', "ictor", 100);
    cr_assert_stdout_eq_str("Char: V, Str: ictor, Int: 100%");
}

Test(my_printf, interleaved_text, .init = redirect_all_std)
{
    my_printf("Before %d middle %s after", 123, "text");
    cr_assert_stdout_eq_str("Before 123 middle text after");
}

Test(my_printf, unsigned_int, .init = redirect_all_std)
{
    my_printf("nombre %u", 0);
    cr_assert_stdout_eq_str("nombre 0");
}

Test(my_printf, unsigned_int_long, .init = redirect_all_std)
{
    my_printf("nombre %u", 123456789);
    cr_assert_stdout_eq_str("nombre 123456789");
}

Test(my_printf, octal_value, .init = redirect_all_std)
{
    my_printf("nombre %o", 64);
    cr_assert_stdout_eq_str("nombre 100");
}

Test(my_printf, hexadec_value, .init = redirect_all_std)
{
    my_printf("result %x %X", 255, 255);
    cr_assert_stdout_eq_str("result ff FF");
}

Test(my_printf, long_int, .init = redirect_all_std)
{
    my_printf("nombre %ld %lld", 123456789L, 123456789012345LL);
    cr_assert_stdout_eq_str("nombre 123456789 123456789012345");
}

Test(my_printf, positive_flag, .init = redirect_all_std)
{
    my_printf("nombre %+d", 123456789);
    cr_assert_stdout_eq_str("nombre +123456789");
}

Test(my_printf, space_flag, .init = redirect_all_std)
{
    my_printf("nombre % d", 123456789);
    cr_assert_stdout_eq_str("nombre  123456789");
}

Test(my_printf, zero_space, .init = redirect_all_std)
{
    my_printf("result %05d", 10);
    cr_assert_stdout_eq_str("result 00010");
}

Test(my_printf, left_align, .init = redirect_all_std)
{
    my_printf("result %-2d", 100);
    cr_assert_stdout_eq_str("result 100");
}

Test(my_printf, left_align_wth_aftr, .init = redirect_all_std)
{
    my_printf("result %-5d %d", 100, 2);
    cr_assert_stdout_eq_str("result 100   2");
}

Test(my_printf, width, .init = redirect_all_std)
{
    my_printf("result %5d", 42);
    cr_assert_stdout_eq_str("result    42");
}

Test(my_printf, zero_before, .init = redirect_all_std)
{
    my_printf("result %.5d", 2);
    cr_assert_stdout_eq_str("result 00002");
}

Test(my_printf, int_extremes, .init = redirect_all_std)
{
    my_printf("result %d %d", INT_MAX, INT_MIN);
    cr_assert_stdout_eq_str("result 2147483647 -2147483648");
}

Test(my_printf, precision_o_x_X, .init = redirect_all_std)
{
    my_printf("result %.4x", 0xA);
    cr_assert_stdout_eq_str("result 000a");
}

Test(my_printf, space_on_negative, .init = redirect_all_std)
{
    my_printf("result % d", -7);
    cr_assert_stdout_eq_str("result -7");
}

Test(my_printf, end_percent, .init = redirect_all_std)
{
    my_printf("end %", -7);
    cr_assert_stdout_eq_str("end %");
}

// === FLAGS COMBOS ===
Test(my_printf, zero_flag_with_precision, .init = redirect_all_std)
{
    my_printf("%05.2d", 3);
    cr_assert_stdout_eq_str("   03");
}

Test(my_printf, width_and_minus_flag, .init = redirect_all_std)
{
    my_printf("%-6dend", 42);
    cr_assert_stdout_eq_str("42    end");
}

Test(my_printf, width_zero_and_minus_flag, .init = redirect_all_std)
{
    my_printf("%-05d", 7);
    cr_assert_stdout_eq_str("7    ");
}

// === UNSIGNED VARIANTS ===
Test(my_printf, unsigned_negative_input, .init = redirect_all_std)
{
    my_printf("%u", -1);
    cr_assert_stdout_eq_str("4294967295");
}

Test(my_printf, long_unsigned, .init = redirect_all_std)
{
    my_printf("%lu", 4294967296UL);
    cr_assert_stdout_eq_str("4294967296");
}

// === ALTERNATE FORM (#) ===
Test(my_printf, alternate_form_hex, .init = redirect_all_std)
{
    my_printf("%#x", 255);
    cr_assert_stdout_eq_str("0xff");
}

Test(my_printf, alternate_form_octal, .init = redirect_all_std)
{
    my_printf("%#o", 8);
    cr_assert_stdout_eq_str("010");
}

// === PRECISION AND WIDTH INTERACTIONS ===
Test(my_printf, precision_greater_than_width, .init = redirect_all_std)
{
    my_printf("%4.6d", 12);
    cr_assert_stdout_eq_str("000012");
}

Test(my_printf, width_greater_than_precision, .init = redirect_all_std)
{
    my_printf("%8.4d", 12);
    cr_assert_stdout_eq_str("    0012");
}

Test(my_printf, zero_precision_zero_value, .init = redirect_all_std)
{
    my_printf("%.0d", 0);
    cr_assert_stdout_eq_str("");
}

Test(my_printf, width_with_zero_precision_zero_value, .init = redirect_all_std)
{
    my_printf("%5.0d", 0);
    cr_assert_stdout_eq_str("     ");
}

// === LENGTH MODIFIERS ===
Test(my_printf, long_long_signed, .init = redirect_all_std)
{
    my_printf("%lld", (long long)9223372036854775807LL);
    cr_assert_stdout_eq_str("9223372036854775807");
}

Test(my_printf, short_overflow, .init = redirect_all_std)
{
    my_printf("%hd", (short)40000);
    cr_assert_stdout_eq_str("-25536");
}

Test(my_printf, char_overflow, .init = redirect_all_std)
{
    my_printf("%hhd", (signed char)200);
    cr_assert_stdout_eq_str("-56");
}

// === HEXA CASE ===
Test(my_printf, hex_with_uppercase_hash, .init = redirect_all_std)
{
    my_printf("%#X", 48879);
    cr_assert_stdout_eq_str("0XBEEF");
}

// === MULTIPLE FLAGS MIX ===
Test(my_printf, multiple_flags_mixed, .init = redirect_all_std)
{
    my_printf("%#08x", 42);
    cr_assert_stdout_eq_str("0x00002a");
}

// === EDGE CASES ===
Test(my_printf, unsupported_specifier, .init = redirect_all_std)
{
    my_printf("test %q done");
    cr_assert_stdout_eq_str("test %q done");
}

Test(my_printf, incomplete_percent, .init = redirect_all_std)
{
    my_printf("end %");
    cr_assert_stdout_eq_str("end %");
}

Test(my_printf, negative_width, .init = redirect_all_std)
{
    my_printf("%-5d", 42);
    cr_assert_stdout_eq_str("42   ");
}
