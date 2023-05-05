/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** lib
*/

int my_str_to_int(char const *str)
{
    int i = 0;
    int nb = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        i++;
    }
    return (nb);
}
