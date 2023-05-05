/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** player_two
*/

#include "navy.h"

int create_seconde_connection(char *pid, char *map)
{
    write(1, "my_pid: ", 8);
    int main_pid = my_str_to_int(pid);
    int my_pid = getpid();
    my_putnbr(getpid());
    write(1, "\n", 1);
    send_number(my_pid, main_pid);
    while (1) {
        if (signals[2] == 1)
            break;
        usleep(4000);
    }
    signals[2] = 0;
    write(1, "successfully connected\n\n", 24);
}

int main_player_two(char *pid, char *filepath)
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
    create_seconde_connection(pid, filepath);
    return main_game(map, my_str_to_int(pid), 2);
}
