/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"

int create_connection(void)
{
    int enemy_pid;
    pid_t player_one_pid = getpid();
    my_putstr("my_pid: ");
    my_putnbr(player_one_pid);
    my_putstr("\nwaiting for enemy connection...\n\n");
    int i = 0;
    while (1) {
        if (signals[1] == 32){
            signals[1] = 0;
            signals[2] = signals[0];
            signals[0] = 0;
            break;
        }
        usleep(4000);
    }
    enemy_pid = signals[2];
    signals[2] = 0;
    my_putstr("enemy connected\n\n");
    send_number(1, enemy_pid);
    return enemy_pid;
}

int verif_map3(int n)
{
    if (n >= 1)
        return 1;
    return 0;
}

int main_player_one(char *filepath)
{
    int verif = 0;
    if (open(filepath, O_RDONLY) == -1)
        return 84;
    int **map = map_verification(filepath);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            verif += verif_map3(map[i][j]);
        }
    }
    if (verif != 14)
        return 84;
    int enemy_pid = create_connection();
    return main_game(map, enemy_pid, 1);
}
