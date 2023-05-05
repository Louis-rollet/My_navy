/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"
int my_printf(char *str, ...);

void display_turn(global_t *global)
{
    if (global->priority == 1) {
        my_printf("attack: ");
        for (int i = 0; global->pos_str[i] != '\0'; i++) {
            pos_str_verif(global);
        }
        if (global->pos_str[0] != '\0' && global->pos_str[1] != '\0')
            my_printf("\n");
    }
    if (global->priority == 2)
        my_printf("waiting for enemy's attack...\n");
}

void display_p2(global_t *global, int i)
{
    my_printf("%d|", i + 1);
    for (int j = 0; j < 8; j++) {
        if (global->map_enemy[i][j] == 0)
            my_printf(".");
        if (global->map_enemy[i][j] == -2)
            my_printf("x");
        if (global->map_enemy[i][j] == -1)
            my_printf("o");
        if (global->map_enemy[i][j] >= 1)
            my_printf("%d", global->map_enemy[i][j]);
        if (j != 7)
            my_printf(" ");
    }
    my_printf("\n");
}

void display_p1(global_t *global, int i)
{
    my_printf("%d|", i + 1);
    for (int j = 0; j < 8; j++) {
        if (global->map[i][j] == 0)
            my_printf(".");
        if (global->map[i][j] == -2)
            my_printf("x");
        if (global->map[i][j] == -1)
            my_printf("o");
        if (global->map[i][j] >= 1)
            my_printf("%d", global->map[i][j]);
        if (j != 7)
            my_printf(" ");
    }
    my_printf("\n");
}

void display(global_t *global)
{
    my_printf("my positions:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        display_p1(global, i);
    }
    my_printf("\n");
    my_printf("enemy's positions:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        display_p2(global, i);
    }
    my_printf("\n");
}
