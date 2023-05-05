/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"
#include "../my_printf/my.h"

void action(int ch, global_t *global)
{
    if (global->priority == 1) {
        if (ch >= 'a' && ch <= 'z' && global->nb_print_letter < 2) {
            global->pos_str[global->nb_print_letter] = ch - 32;
            global->nb_print_letter++;
        }
        if (ch >= '0' && ch <= '9' && global->nb_print_letter < 2) {
            global->pos_str[global->nb_print_letter] = ch;
            global->nb_print_letter++;
        }
    }
    return;
}

void reset_turn(global_t *global)
{
    global->wrong_pos[0] = '\0';
    global->wrong_pos[1] = '\0';
    global->wrong_pos[2] = '\0';
    global->pos_str[0] = '\0';
    global->pos_str[1] = '\0';
    global->nb_print_letter = 0;
    signals[2] = 0;
    signals[1] = 0;
}

int detect_collide(global_t *global)
{
    if (global->map[signals[2] % 10][signals[2] / 10] == 0)
        return (0);
    if (global->map[signals[2] % 10][signals[2] / 10] < 0)
        return (2);
    else
        return (1);
}
