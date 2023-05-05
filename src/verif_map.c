/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"

int my_printf(char *str, ...);

int is_nb(char c)
{
    if (c >= '0' && c <= '8')
        return 1;
    return 0;
}

int is_let(char c)
{
    if (c >= 'A' && c <= 'H')
        return 1;
    return 0;
}

int boat_size_nb(char *str, int i)
{
    if (str[i] - '0' - 1 != (str[i + 6] - '0') - (str[i + 3] - '0'))
        return 84;
    return 0;
}

int boat_size_let(char *str, int i)
{
    if (str[i] - '0' - 1 != (str[i + 5] - '0') - (str[i + 2] - '0'))
        return 84;
    return 0;
}

int verif_map(char *str)
{
    if (str == NULL)
        return 84;
    if (str[0] != '2' || str[8] != '3' || str[16] != '4' || str[24] != '5')
        return 84;
    for (int i = 0; i < 32; i += 8) {
        if (is_nb(str[i]) != 1 || is_nb(str[i + 3]) != 1 ||
        is_nb(str[i + 6]) != 1)
            return 84;
        if (str[i + 1] != ':' || str[i + 4] != ':')
            return 84;
        if (is_let(str[i + 2]) != 1 || is_let(str[i + 5]) != 1)
            return 84;
        if (str[i + 2] == str[i + 5] && boat_size_nb(str, i) == 84)
            return 84;
        if (str[i + 3] == str[i + 6] && boat_size_let(str, i) == 84)
            return 84;
    }
    return 0;
}
