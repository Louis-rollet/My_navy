/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"
int my_printf(char *str, ...);

int loop_win(global_t *global, int nb, int i)
{
    for (int j = 0; j < 8; j++) {
        if (global->map[i][j] >= 1)
            return 1;
    }
    return 0;
}

int loop_other_win(global_t *global, int nb, int i)
{
    for (int j = 0; j < 8; j++) {
        if (global->map_enemy[i][j] == -2)
            nb++;
    }
    return nb;
}

int verif_win(global_t *global)
{
    int nb = 0, nb2 = 0;
    for (int i = 0; i < 8; i++) {
        nb += loop_win(global, nb, i);
    }
    if (nb == 0) {
        display(global);
        my_printf("Enemy won\n\n");
        global->return_value = 1;
        return 1;
    }
    for (int i = 0; i < 8; i++) {
        nb2 += loop_other_win(global, 0, i);
    }
    if (nb2 == 14) {
        display(global);
        my_printf("I won\n\n");
        global->return_value = 0;
        return 1;
    }
    return 0;
}

int is_zero(int i)
{
    if (i != 0)
        return 84;
    return 0;
}
