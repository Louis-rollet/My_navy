/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"
int my_printf(char *str, ...);

void verif_hit_three(global_t *global)
{
    if (detect_collide(global) == 2) {
        my_printf("%c%c: missed\n\n", (signals[2] / 10) + 65,
        (signals[2] % 10) + 49);
        send_number(3, global->enemy_pid);
        signals[2] = 0;
    }
}

void do_hit_player2(global_t *global)
{
    if (detect_collide(global) == 1) {
        my_printf("%c%c: hit\n\n", (signals[2] / 10) + 65,
        (signals[2] % 10) + 49);
        global->map[signals[2] % 10][signals[2] / 10] = -2;
        send_number(2, global->enemy_pid);
        signals[2] = 0;
    } else if (detect_collide(global) == 0){
        my_printf("%c%c: missed\n\n", (signals[2] / 10) + 65,
        (signals[2] % 10) + 49);
        global->map[signals[2] % 10][signals[2] / 10] = -1;
        send_number(1, global->enemy_pid);
        signals[2] = 0;
    } else
        verif_hit_three(global);
    global->turn++;
    global->nb_print = global->nb_print + 3;
    global->priority = 1;
    reset_turn(global);
    if (global->turn != 2)
        display_turn(global);
}

void turn_action(global_t *global)
{
    int nb = 0;
    if (global->priority == 1) {
        pos_str_verif(global);
        if (global->pos_str[0] != '\0' && global->pos_str[1] != '\0') {
            nb = global->pos_str[0] - 65;
            nb = nb * 10 + (global->pos_str[1] - 49);
            send_number(nb + 11, global->enemy_pid);
            do_hit_player1(global, nb);
        }
    }
    if (global->priority == 2) {
        if (signals[2] >= 1) {
            signals[2] = signals[2] - 11;
            int nb = signals[2];
            do_hit_player2(global);
        }
    }
}

int main_loop(global_t *global)
{
    if (verif_win(global) == 1) {
        global->stop = 1;
        return 1;
    }
    if (global->turn == 2){
        global->display = 1;
        global->turn = 0;
    }
    if (global->display == 1) {
        display(global);
        if (global->stop != 0)
            return 1;
        signals[1] = 0;
        signals[2] = 0;
        display_turn(global);
        global->display = 0;
    }
    return 0;
}

int main_game(int **map, int enemy_pid, int turn)
{
    global_t *global = malloc(sizeof(global_t));
    init_struct(global, map, enemy_pid, turn);
    int ch = 0;
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t bytes_read;
    global->display = 1;
    while (global->stop == 0) {
        if (main_loop(global) == 1)
            return global->return_value;
        if (global->priority == 1) {
            bytes_read = getline(&buffer, &buffer_size, stdin);
            global->pos_str[0] = buffer[0];
            global->pos_str[1] = buffer[1];
            action(ch, global);
        }
        turn_action(global);
        usleep(4000);
    }
    return 0;
}
