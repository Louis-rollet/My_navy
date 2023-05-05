/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"

void handler(int sig)
{
    if (sig == SIGUSR1){
        signals[0] = (signals[0] << 1) + 1;
        signals[1]++;
    }
    if (sig == SIGUSR2){
        signals[0] = (signals[0] << 1);
        signals[1]++;
    }
    if (signals[1] == 32){
        signals[2] = signals[0];
    }
}

void define_signal(void)
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}

int main_next(char **av)
{
    int error = 0;
    int fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        char *str = load_file_in_str(av[2]);
        if (verif_map(str) == 84)
            return 84;
        error = main_player_two(av[1], av[2]);
    } else {
        char *str = load_file_in_str(av[1]);
        if (verif_map(str) == 84)
            return 84;
        error = main_player_one(av[1]);
    }
    close(fd);
    if (error == 84)
        return 84;
    return error;
}

int main(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return 84;
    signals = malloc(sizeof(int) * 3);
    signals[0] = 0;
    signals[1] = 0;
    signals[2] = 0;
    int verif_return = 0;
    define_signal();
    int verif_error = main_next(av);
    if (verif_error == 84)
        return 84;
    return verif_error;
}
