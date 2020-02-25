/*
** EPITECH PROJECT, 2020
** PSU_navy
** File description:
** pre_check
*/

#include "my.h"
#include "main.h"

static int basic_check(char *fc)
{
    if (fc[0] != '2' || fc[8] != '3' || fc[16] != '4' || fc[24] != '5' ||
        fc[1] != ':' || fc[4] != ':' || fc[9] != ':' || fc[12] != ':' ||
        fc[17] != ':' || fc[20] != ':' || fc[25] != ':' || fc[28] != ':' ||
        fc[7] != '\n' || fc[15] != '\n' || fc[23] != '\n' || fc[31] != '\n')
        return (-1);
    return (0);
}

static int get_diff(char *line)
{
    return (line[2] - line[5] + line[3] - line[6]);
}

static int pos_check(char *fc)
{
    for (int i = 0; i < 25; i += 8) {
        if (!(((fc[i + 2] - fc[i + 5]) != 0) !=
            ((fc[i + 3] - fc[i + 6]) != 0)) || fc[i + 2] > 'H' ||
            fc[i + 2] < 'A' || fc[i + 5] > 'H' || fc[i + 5] < 'A' ||
            fc[i + 3] > '8' || fc[i + 3] < '1' || fc[i + 6] > '8' ||
            fc[i + 6] < '1' || get_diff(fc + i) != fc[i] - '0')
            return (-1);
    }
    return (0);
}

int pre_check(char *filepath)
{
    char *file_content = NULL;

    filepath = seek_n_read(filepath);
    if (!filepath)
        return (-1);
    if (my_strlen(filepath) != 32)
        return (-1);
    if (basic_check(file_content) == -1)
        return (-1);
    if (pos_check(file_content) == -1)
        return (-1);
    free(filepath);
    return (0);
}