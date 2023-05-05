/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/
#include "navy.h"

char *load_file_in_str(char const * filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    char *buffer = malloc((5000) * sizeof(char));
    for (int i = 0; i < 5000; i++)
        buffer[i] = '\0';
    read(fd, buffer, 5000);
    return buffer;
}
