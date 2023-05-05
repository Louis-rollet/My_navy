/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"
#include "../my_printf/my.h"

void init_struct2(global_t *global, int enemy_pid, int turn)
{
    global->enemy_pid = enemy_pid;
    global->my_pid = getpid();
    global->turn = 0;
    global->priority = turn;
    global->win = 0;
    global->nb_print = 0;
    global->pos_str = malloc(sizeof(char) * 3);
    for (int i = 0; i < 3; i++)
        global->pos_str[i] = '\0';
}

void init_struct(global_t *global, int **map, int enemy_pid, int turn)
{
    signals[0] = 0;
    signals[1] = 0;
    signals[2] = 0;
    global->display = 0;
    global->wrong_pos = malloc(sizeof(char) * 3);
    for (int i = 0; i < 3; i++)
        global->wrong_pos[i] = '\0';
    global->stop = 0;
    global->map = map;
    global->map_enemy = malloc(sizeof(int *) * 8);
    for (int i = 0; i < 8; i++) {
        global->map_enemy[i] = malloc(sizeof(int) * 8);
        for (int j = 0; j < 8; j++)
            global->map_enemy[i][j] = 0;
    }
    global->return_value = 0;
    init_struct2(global, enemy_pid, turn);
}
