/*
** EPITECH PROJECT, 2022
** Project mini-printf
** File description:
** Error gestion
*/

int veriferror(int cpt, int cpt_error)
{
    if (cpt == cpt_error - 1) {
        return -1;
    } else {
        return cpt;
    }
}
