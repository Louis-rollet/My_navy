/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"
int my_printf(char *str, ...);

int wrong_pos1(global_t *global)
{
    if (global->pos_str[0] < 'A' || global->pos_str[0] > 'H') {
        if (global->wrong_pos[0] == '\0')
            global->nb_print = global->nb_print + 2;
        global->wrong_pos[0] = global->pos_str[0];
        global->wrong_pos[1] = global->pos_str[1];
        global->wrong_pos[2] = '\0';
        global->pos_str[0] = '\0';
        global->pos_str[1] = '\0';
        global->nb_print_letter = 0;
        return 84;
    }
    return 0;
}

int wrong_pos2(global_t *global)
{
    if (global->pos_str[0] >= '0' && global->pos_str[0] <= '9') {
        if (global->wrong_pos[0] == '\0')
            global->nb_print = global->nb_print + 2;
        global->wrong_pos[0] = global->pos_str[0];
        global->wrong_pos[1] = global->pos_str[1];
        global->wrong_pos[2] = '\0';
        global->pos_str[0] = '\0';
        global->pos_str[1] = '\0';
        global->nb_print_letter = 0;
        return 84;
    }
    return 0;
}

int wrong_pos3(global_t *global)
{
    if (global->pos_str[1] < '1' || global->pos_str[1] > '8') {
        if (global->wrong_pos[0] == '\0')
            global->nb_print = global->nb_print + 2;
        global->wrong_pos[0] = global->pos_str[0];
        global->wrong_pos[1] = global->pos_str[1];
        global->wrong_pos[2] = '\0';
        global->pos_str[0] = '\0';
        global->pos_str[1] = '\0';
        global->nb_print_letter = 0;
        return 84;
    }
    return 0;
}

void pos_str_verif(global_t *global)
{
    int error = 0;
    for (int i = 0; i < 3; i++)
        global->wrong_pos[i] = '\0';
    if (global->pos_str[0] != '\0' && global->pos_str[1] != '\0') {
        error = wrong_pos1(global);
    }
    if (global->pos_str[0] != '\0') {
        error = wrong_pos2(global);
    }
    if (global->pos_str[1] != '\0') {
        error = wrong_pos3(global);
    }
    if (global->wrong_pos[0] != '\0' || error >= 1) {
        my_printf("wrong position\n");
        my_printf("attack: ");
    }
}
