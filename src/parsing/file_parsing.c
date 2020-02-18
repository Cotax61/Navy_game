/*
** EPITECH PROJECT, 2019
** place_ navy
** File description:
** place navy, only need a filename
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"
#include "my.h"

void my_put_navy(char **map, char **navy, int navy_nbr, int direction)
{
    int row = (navy[navy_nbr - 2][3] - 48) + 1;
    int col = (navy[navy_nbr - 2][2] - 65) * 2 + 2;

    for (int i = 0; i != navy_nbr; i++)
        switch (direction) {
        case 1:
            map[row - i][col] = navy_nbr + 48;
            break;
        case 2:
            map[row][col - (i * 2)] = navy_nbr + 48;
            break;
        case 3:
            map[row + i][col] = navy_nbr + 48;
            break;
        case 4:
            map[row][col + (i * 2)] = navy_nbr + 48;
            break;
        }
}

void navy_condition(char **map, char **navy, int line)
{
    if (navy[line][3] > navy[line][6])
        my_put_navy(map, navy, line + 2, 1);
    if (navy[line][2] > navy[line][5])
        my_put_navy(map, navy, line + 2, 2);
    if (navy[line][3] < navy[line][6])
        my_put_navy(map, navy, line + 2, 3);
    if (navy[line][2] < navy[line][5])
        my_put_navy(map, navy, line + 2, 4);
}

char **get_navy(char *file)
{
    char *buffer = NULL;
    char **position = NULL;

    buffer = seek_n_read(file);
    position = my_str_split(buffer, '\n');
    free(buffer);
    return (position);
}

char **place_navy(char *filename, char **map)
{
    char **buffer = get_navy(filename);

    for (int i = 0; i != 4; i++)
        navy_condition(map, buffer, i);
    return (map);
}