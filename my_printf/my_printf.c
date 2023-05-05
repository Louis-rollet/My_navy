/*
** EPITECH PROJECT, 2022
** Project mini-printf
** File description:
** main func
*/
#include "my.h"

int two_flags(int i, char c)
{
    if (c == 'l' || c == 'h' || c == '#') {
        return i + 2;
    }
    return i + 1;
}

int my_printf_loop(char *format, va_list ap)
{
    int cpt_error, j, b, cpt = 0;
    for (int i = 0; format[i]; i++) {
        b = 0;
        j = i;
        i = verif_space(format, i);
        if (format[i] != '%' && i == j)
            b++, cpt += my_putchar(format[i]);
        if (format[i + 1] == 'n' && format[i] == '%'){
            cpt_to_adress(ap, cpt);
            i++, b++;
        }
        if (b == 0) {
            cpt_error = cpt;
            cpt = veriferror(cpt += print_arg(format, ap, i + 1), cpt_error);
            i = two_flags(i, format[i + 1]);
        }
        cpt = verif_cpt_bug(cpt_error, cpt, format[i]);
    }
    return cpt;
}

int my_printf(char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int cpt = my_printf_loop(format, ap);
    va_end(ap);
    return cpt;
}
