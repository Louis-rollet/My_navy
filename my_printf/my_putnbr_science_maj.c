/*
** EPITECH PROJECT, 2022
** B-CPE-101-MPL-1-1-myprintf-kylian.labrador
** File description:
** my_putnbr_science_maj
*/
#include <stdarg.h>
#include "my.h"

int my_putnbr_science_pos_maj(double nb)
{
    int n = 0, counter = 0;
    double b = nb;
    if (b < 0){
        b = -nb;
    }
    while (b >= 10){
        b = b / 10;
        n++;
    }
    counter += my_putnbr_float(nb / pui(10, n - 1));
    my_putstr("E+");
    if (n < 10){
        my_putchar('0');
        counter++;
    }
    counter += my_putnbr(n);
    return counter + 2;
}

int my_putnbr_science_neg_maj(double nb)
{
    int n = 0;
    double b = nb;
    int counter = 0;
    if (b < 0){
        b = -nb;
    }
    while (b < 1){
        b = b * 10;
        n++;
    }
    counter += my_putnbr_float(nb * pui_neg(10, n - 1));
    my_putstr("E-");
    if (n < 10){
        my_putchar('0');
        counter++;
    }
    counter += my_putnbr(n);
    return counter + 2;
}

int my_putnbr_science_maj_ap(va_list ap)
{
    double nb = va_arg(ap, double);
    if (my_abs(nb) >= 1.0 || my_abs(nb) == 0.0) {
        return my_putnbr_science_pos_maj(nb);
    }
    return my_putnbr_science_neg_maj(nb);
}
