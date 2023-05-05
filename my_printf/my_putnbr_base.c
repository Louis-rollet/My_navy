/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/
#include <stdarg.h>
#include "my.h"

int my_putnbr_base(unsigned int nb, char *base)
{
    if (nb >= 0){
        int n = 0;
        int res = my_strlen(base);
        if (nb < res && nb >= 0){
            my_putchar(base[nb]);
            return 1;
        }
        n += my_putnbr_base(nb / res, base);
        my_putchar(base[nb % res]);
        return n + 1;
    } else {
        nb = 4294967296 - nb;
        return my_putnbr_base(nb, base);
    }
}

int my_putnbr_hex_ap(va_list ap)
{
    return my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
}

int my_putnbr_hex_ap_cap(va_list ap)
{
    return my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
}

int my_putnbr_bin_ap(va_list ap)
{
    return my_putnbr_base(va_arg(ap, unsigned int), "01");
}

int my_putnbr_oc_ap(va_list ap)
{
    return my_putnbr_base(va_arg(ap, unsigned int), "01234567");
}
