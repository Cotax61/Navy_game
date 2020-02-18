/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** seek_n_read
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *seek_n_read(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    off_t offset = 0;
    char *buffer = 0;
    int rd_size = 0;

    if (fd == -1)
        return (NULL);
    offset = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    buffer = malloc(sizeof(char) * offset + 1);
    if (!buffer)
        return (buffer);
    rd_size = read(fd, buffer, offset);
    buffer[rd_size] = '\0';
    close(fd);
    return (buffer);
}