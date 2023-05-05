/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"

void copy_str(char *str, char *dest, int nb)
{
    for (int i = 0; i < nb + 1; i++)
        dest[i] = '\0';
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        dest[i] = str[i];
    }
}

void get_string_from_lines(char** map, int num_lines, char* str)
{
    int nb = 0, k = 0, i = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            map[k] = malloc(sizeof(char) * nb + 1);
            copy_str(&str[i - nb], map[k], nb);
            nb = 0;
            k++;
            continue;
        }
        nb++;
    }
    map[k] = malloc(sizeof(char) * (nb + 1));
    for (int i = 0; i < nb + 1; i++)
        map[k][i] = '\0';
    copy_str(&str[i - nb], map[k], nb);
}

int loop_map(char **tab, int **map, int i)
{
    int verif = 0;
    for (int j = tab[i][2] - 18 - '0' + 1; j <= tab[i][5] - 18 - '0' + 1; j++) {
        for (int k = tab[i][3] - '0' - 1; k <= tab[i][6] - '0' - 1; k++) {
            verif += is_zero(map[k][j]);
            map[k][j] = tab[i][0] - '0';
        }
    }
    return verif;
}

int **map_add(char **tab)
{
    int verif = 0;
    int **map = malloc(sizeof(int *) * 8);
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(int) * 8);
        for (int j = 0; j < 8; j++)
            map[i][j] = 0;
    }
    for (int i = 0; i < 4; i++) {
        if (loop_map(tab, map, i) > 0)
            return NULL;
    }
    return map;
}

int **map_verification(char *filepath)
{
    int num_lines = 0;
    char *str = load_file_in_str(filepath);
    if (verif_map(str) == 84)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            num_lines++;
    }
    char **tab = malloc(sizeof(char *) * num_lines);
    get_string_from_lines(tab, num_lines, str);
    int **map = map_add(tab);
    return map;
}
