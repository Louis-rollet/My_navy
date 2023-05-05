/*
** EPITECH PROJECT, 2022
** B-CPE-101-MPL-1-1-myprintf-kylian.labrador
** File description:
** hashtag
*/
#include "my.h"

int my_putnbr_hex_hash_ap(va_list ap)
{
    my_putstr("0x");
    return my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef") + 2;
}

int my_putnbr_hex_hash_cap_ap(va_list ap)
{
    my_putstr("0X");
    return my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF") + 2;
}

int my_putnbr_bin_hash_ap(va_list ap)
{
    my_putstr("0b");
    return my_putnbr_base(va_arg(ap, unsigned int), "01") + 2;
}

int my_putnbr_bin_hash_cap_ap(va_list ap)
{
    my_putstr("0B");
    return my_putnbr_base(va_arg(ap, unsigned int), "01") + 2;
}

int my_putnbr_oc_hash_ap(va_list ap)
{
    my_putchar('0');
    return my_putnbr_base(va_arg(ap, unsigned int), "01234567") + 1;
}
