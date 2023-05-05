/*
** EPITECH PROJECT, 2022
** Project my_printf
** File description:
** func for multiple flag
*/

#include "my.h"

function_t funcs_for_l[] = {
    {'i', my_putnbr_li_ap},
    {'d', my_putnbr_li_ap},
    {'x', my_putnbr_hex_li_ap},
    {'X', my_putnbr_hex_li_ap_cap},
    {'b', my_putnbr_bin_li_ap},
    {'o', my_putnbr_oc_hash_ap},
    {'c', my_putchar_ap},
    {'s', my_putstr_ap},
    {'S', my_putstr_printable_ap},
    {'%', my_putchar_perc},
    {'u', my_putnbr_un_ap},
    {'f', my_putnbr_float_ap},
    {'e', my_putnbr_science_ap}
};

function_t funcs_for_h[] = {
    {'i', my_putnbr_hi_ap},
    {'d', my_putnbr_hi_ap},
    {'x', my_putnbr_hex_hi_ap},
    {'X', my_putnbr_hex_hi_ap_cap},
    {'b', my_putnbr_bin_hi_ap},
    {'o', my_putnbr_oc_hash_ap},
    {'c', my_putchar_ap},
    {'s', my_putstr_ap},
    {'S', my_putstr_printable_ap},
    {'%', my_putchar_perc},
    {'u', my_putnbr_un_ap},
    {'f', my_putnbr_float_ap},
    {'e', my_putnbr_science_ap}
};

function_t funcs_for_hash[] = {
    {'b', my_putnbr_bin_hash_ap},
    {'B', my_putnbr_bin_hash_cap_ap},
    {'x', my_putnbr_hex_hash_ap},
    {'X', my_putnbr_hex_hash_cap_ap},
    {'o', my_putnbr_oc_hash_ap},
    {'c', my_putchar_ap},
    {'d', my_putnbr_ap},
    {'i', my_putnbr_ap},
    {'s', my_putstr_ap},
    {'S', my_putstr_printable_ap},
    {'%', my_putchar_perc},
    {'u', my_putnbr_un_ap},
    {'f', my_putnbr_float_ap},
    {'e', my_putnbr_science_ap}
};

int print_arg2(char *format, va_list ap, int i)
{
    for (int j = 0; j < 14; j++) {
        if (funcs_for_l[j].c == format[i]) {
            return funcs_for_l[j].ptr(ap);
        }
    }
    return -1;
}

int print_arg3(char *format, va_list ap, int i)
{
    for (int j = 0; j < 14; j++) {
        if (funcs_for_h[j].c == format[i]) {
            return funcs_for_h[j].ptr(ap);
        }
    }
    return -1;
}

int print_arg4(char *format, va_list ap, int i)
{
    for (int j = 0; j < 14; j++) {
        if (funcs_for_hash[j].c == format[i]) {
            return funcs_for_hash[j].ptr(ap);
        }
    }
    return -1;
}
