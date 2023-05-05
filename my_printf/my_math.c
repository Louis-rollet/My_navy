/*
** EPITECH PROJECT, 2022
** Project my_printf
** File description:
** fonc math
*/

long int pui(long int p, int nb)
{
    long int i = p;
    if (nb == -1)
        return 1;
    if (nb == 0) {
        return p;
    } else {
        for (int n = 0; n < nb; n++){
            p = p * i;
        }
    }
    return p;
}

long int pui_neg(long int p, int nb)
{
    long int i = p;
    if (nb == 0) {
        return p;
    } else {
        for (int n = 0; n < nb; n++){
            p = p * i;
        }
    }
    return p;
}

double my_abs(double nb)
{
    if (nb >= 0.0) {
        return nb;
    }
    return -nb;
}
