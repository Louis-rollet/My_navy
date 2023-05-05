/*
** EPITECH PROJECT, 2022
** Project mini-printf
** File description:
** print arg
*/

#include <stdarg.h>
#include "my.h"

function_t funcs[] = {
    {'c', my_putchar_ap},
    {'d', my_putnbr_ap},
    {'i', my_putnbr_ap},
    {'s', my_putstr_ap},
    {'S', my_putstr_printable_ap},
    {'%', my_putchar_perc},
    {'x', my_putnbr_hex_ap},
    {'X', my_putnbr_hex_ap_cap},
    {'u', my_putnbr_un_ap},
    {'b', my_putnbr_bin_ap},
    {'B', my_putnbr_bin_ap},
    {'f', my_putnbr_float_ap},
    {'e', my_putnbr_science_ap},
    {'E', my_putnbr_science_maj_ap},
    {'o', my_putnbr_oc_ap},
    {'p', display_p_in_hex_ap}
};

int verif_2_flags(char *format, int i)
{
    if (format[i] == 'l' || format[i] == 'h' || format[i] == '#') {
        return 1;
    }
    return 0;
}

int print_argi(char *format, va_list ap, int i)
{
    if (format[i] == 'l')
        return print_arg2(format, ap, i + 1);
    if (format[i] == 'h')
        return print_arg3(format, ap, i + 1);
    return print_arg4(format, ap, i + 1);
}

int print_arg(char *format, va_list ap, int i)
{
    if (verif_2_flags(format, i))
        return print_argi(format, ap, i);
    for (int j = 0; j < 16; j++) {
        if (funcs[j].c == format[i]) {
            return funcs[j].ptr(ap);
        }
    }
    return -1;
}
