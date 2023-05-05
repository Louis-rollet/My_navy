/*
** EPITECH PROJECT, 2022
** Project my_printf
** File description:
** putnbr with long int
*/

#include <stdarg.h>
#include "my.h"

int my_putnbr_base_hi(int nb, char *base)
{
    if (nb >= 0){
        long int n = 0;
        int res = my_strlen(base);
        if (nb < res){
            my_putchar(base[nb]);
            return 1;
        }
        n += my_putnbr_base_hi(nb / res, base);
        my_putchar(base[nb % res]);
        return n + 1;
    } else {
        nb = 65536 + nb;
        return my_putnbr_base_hi(nb, base);
    }
}

int my_putnbr_hex_hi_ap(va_list ap)
{
    return my_putnbr_base_hi(va_arg(ap, int), "0123456789abcdef");
}

int my_putnbr_hex_hi_ap_cap(va_list ap)
{
    return my_putnbr_base_hi(va_arg(ap, int), "0123456789ABCDEF");
}

int my_putnbr_bin_hi_ap(va_list ap)
{
    return my_putnbr_base_hi(va_arg(ap, int), "01");
}
