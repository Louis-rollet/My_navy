/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** my_putnbr_float
*/

#include <stdarg.h>
#include "my.h"

int my_putnbr_float(double nb)
{
    unsigned long int n = 0, counter = 0, j = 0;
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        counter++;
    }
    unsigned long int i = nb;
    for (float a = nb; a >= 10; n++)
        a = a / 10;
    counter += my_putnbr(i);
    my_putchar('.');
    for (int k = 0; k < 6; k++){
        nb = nb * 10;
        j = nb;
        my_putchar('0' + (j % 10));
        counter++;
    }
    return counter + 1;
}

int my_putnbr_science_pos(double nb)
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
    my_putstr("e+");
    if (n < 10){
        my_putchar('0');
        counter++;
    }
    counter += my_putnbr(n);
    return counter + 2;
}

int my_putnbr_science_neg(double nb)
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
    my_putstr("e-");
    if (n < 10){
        my_putchar('0');
        counter++;
    }
    counter += my_putnbr(n);
    return counter + 2;
}

int my_putnbr_float_ap(va_list ap)
{
    return my_putnbr_float(va_arg(ap, double));
}

int my_putnbr_science_ap(va_list ap)
{
    double nb = va_arg(ap, double);
    if (my_abs(nb) >= 1.0 || my_abs(nb) == 0.0) {
        return my_putnbr_science_pos(nb);
    }
    return my_putnbr_science_neg(nb);
}
