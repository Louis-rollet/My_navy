/*
** EPITECH PROJECT, 2022
** B-CPE-101-MPL-1-1-myprintf-kylian.labrador
** File description:
** space_and_bug
*/
#include "my.h"

int verif_space(char *format, int i)
{
    if (format[i] == '%' && format[i + 1] == ' ') {
        while (format[i + 1] == ' ')
            i++;
    }
    return i;
}

int verif_cpt_bug(int cpt_error, int cpt, char c)
{
    if (cpt == -1) {
        my_putchar('%');
        my_putchar(c);
        return cpt_error + 2;
    }
    return cpt;
}
