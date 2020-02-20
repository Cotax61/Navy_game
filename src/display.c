/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** display
*/

#include "my.h"

void display_pos(char **map1, char **map2)
{
    my_putstr("\nmy positions:\n");
    my_put_array(map1, 1, 1);
    my_putstr("enemy's positions:\n");
    my_put_array(map2, 1, 1);
}