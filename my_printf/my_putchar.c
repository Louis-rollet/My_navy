/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** my_putchar
*/

#include <unistd.h>
#include <stdarg.h>

int my_putchar(char c)
{
    return write(1, &c, 1);
}

int my_putchar_ap(va_list ap)
{
    return my_putchar(va_arg(ap, int));
}

int my_putchar_perc(va_list ap)
{
    return write(1, "%", 1);
}
