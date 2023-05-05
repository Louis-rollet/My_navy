/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** my_putnbr
*/

#include <stdarg.h>
#include "my.h"

int my_putnbr_hi(short nb)
{
    int n = 0;
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        n++;
    }
    if (nb < 10) {
        my_putchar('0' + nb);
        return 1;
    }
    n += my_putnbr_hi(nb / 10);
    my_putchar((nb % 10) + '0');
    return n + 1;
}

int my_putnbr_hi_ap(va_list ap)
{
    return my_putnbr_hi(va_arg(ap, int));
}
