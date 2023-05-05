/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** verif_hit_three
*/

#include "navy.h"
int my_printf(char *str, ...);

void do_hit_three(global_t *global, int nb)
{
    if (signals[2] == 2) {
        my_printf("%c%c: hit\n\n", (nb / 10) + 65, (nb % 10) + 49);
        global->map_enemy[nb % 10][nb / 10] = -2;
        signals[2] = 0;
    }
    if (signals[2] == 3) {
        my_printf("%c%c: missed\n\n", (nb / 10) + 65, (nb % 10) + 49);
        signals[2] = 0;
    }
}

void do_hit_player1(global_t *global, int nb)
{
    while (1){
        if (signals[2] != 0)
            break;
        usleep(4000);
    }
    if (signals[2] == 1) {
        my_printf("%c%c: missed\n\n", (nb / 10) + 65, (nb % 10) + 49);
        global->map_enemy[nb % 10][nb / 10] = -1;
        signals[2] = 0;
    }
    do_hit_three(global, nb);
    global->turn++, global->priority = 2;
    global->nb_print = global->nb_print + 2;
    reset_turn(global);
    if (global->turn != 2)
        display_turn(global);
}
