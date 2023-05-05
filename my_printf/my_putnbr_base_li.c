/*
** EPITECH PROJECT, 2022
** Project my_printf
** File description:
** putnbr with long int
*/

#include <stdarg.h>
#include "my.h"

int my_putnbr_base_li(long int nb, char *base)
{
        long int n = 0;
        int res = my_strlen(base);
        if (nb < res){
            my_putchar(base[nb]);
            return 1;
        }
        n += my_putnbr_base_li(nb / res, base);
        my_putchar(base[nb % res]);
        return n + 1;
}

int my_putnbr_hex_li_ap(va_list ap)
{
    return my_putnbr_base_li(va_arg(ap, long int), "0123456789abcdef");
}

int my_putnbr_hex_li_ap_cap(va_list ap)
{
    return my_putnbr_base_li(va_arg(ap, long int), "0123456789ABCDEF");
}

int my_putnbr_bin_li_ap(va_list ap)
{
    return my_putnbr_base_li(va_arg(ap, long int), "01");
}
