/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"

void send_number(int to_send, int pid)
{
    int i = 0;
    int temp = to_send;
    int num_bits = 0;
    for (i = 31; i >= 0; i--) {
        if (to_send >> i & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(4000);
    }
}
