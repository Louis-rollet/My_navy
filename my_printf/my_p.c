/*
** EPITECH PROJECT, 2022
** Project my_printf
** File description:
** flag p
*/

#include "my.h"

int my_putnbr_base_void(void *n, char *base)
{
    int nb = 0;
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

int display_p_in_hex(void *ptr)
{
    my_putnbr_base_void(ptr, "0123456789ABCDEF");
}

int display_p_in_hex_ap(va_list ap)
{
    return display_p_in_hex(va_arg(ap, void *));
}
