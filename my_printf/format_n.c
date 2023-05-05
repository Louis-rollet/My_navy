/*
** EPITECH PROJECT, 2022
** Project my_printf
** File description:
** for %n
*/

#include <stdarg.h>

void cpt_to_adress(va_list ap, int cpt)
{
    int *adress = va_arg(ap, int *);
    *adress = cpt;
}
