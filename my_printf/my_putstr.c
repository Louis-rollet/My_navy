/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** my_putstr
*/
#include "my.h"

int my_putstr(char *str)
{
    int i = 0;
    for (; str[i]; i++) {
        my_putchar(str[i]);
    }
    return i;
}

int my_putstr_printable(char *str)
{
    int i = 0;
    int c = 0;
    for (; str[i]; i++) {
        if (str[i] > 31 && str[i] < 127) {
            my_putchar(str[i]);

        } else {
            my_putchar('\\');
            c += my_putnbr_base(str[i], "012345678");
        }
    }
    return i + c;
}

int my_putstr_ap(va_list ap)
{
    return my_putstr(va_arg(ap, char *)) + 1;
}

int my_putstr_printable_ap(va_list ap)
{
    return my_putstr_printable(va_arg(ap, char *));
}
