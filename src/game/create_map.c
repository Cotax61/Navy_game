/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** create_map
*/

#include <stdlib.h>
#include "my.h"

char **place_navy(char *filepath, char **map);

void create_base(char **map)
{
    map[0] = my_strdup(" |A B C D E F G H\0");
    map[1] = my_strdup("-+---------------\0");
    map[2] = my_strdup("1|. . . . . . . .\0");
    map[3] = my_strdup("2|. . . . . . . .\0");
    map[4] = my_strdup("3|. . . . . . . .\0");
    map[5] = my_strdup("4|. . . . . . . .\0");
    map[6] = my_strdup("5|. . . . . . . .\0");
    map[7] = my_strdup("6|. . . . . . . .\0");
    map[8] = my_strdup("7|. . . . . . . .\0");
    map[9] = my_strdup("8|. . . . . . . .\0");
    map[10] = NULL;
}

char **create_map(char *filepath)
{
    char **map = NULL;

    map = malloc(sizeof(char *) * 11);
    map[10] = 0;
    create_base(map);
    if (filepath != NULL)
        map = place_navy(filepath, map);
    return (map);
}