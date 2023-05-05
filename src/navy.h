/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** my
*/
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include  <signal.h>
#include  <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ucontext.h>

#ifndef MY_H_
    #define MY_H_

extern int *signals;

typedef struct global {
    int **map;
    int **map_enemy;
    int enemy_pid;
    int my_pid;
    int turn;
    int win;
    int stop;
    int nb_print;
    int nb_print_letter;
    int priority;
    char *pos_str;
    char *wrong_pos;
    char *enemy_attack;
    int display;
    int return_value;
} global_t;

int main_player_two(char *pid, char *map);
int main_player_one(char *);
int my_strlen(char const *str);
int my_putchar(char c);
int my_putstr(char const *str);
int my_str_to_int(char const *str);
int my_putnbr(int nb);
char *load_file_in_str(char const * filepath);
int main_game(int **map, int enemy_pid, int turn);
int **map_verification(char *filepath);
void send_number(int num, int pid);
void pos_str_verif(global_t *global);
void display(global_t *global);
void display_turn(global_t *global);
void init_struct(global_t *global, int **map, int enemy_pid, int turn);
int detect_win(global_t *global);
int detect_collide(global_t *global);
void reset_turn(global_t *global);
void action(int ch, global_t *global);
int verif_map(char *str);
int is_zero(int i);
int verif_map3(int n);
void do_hit_player1(global_t *global, int nb);
int verif_win(global_t *global);
#endif /* !MY_H_ */
