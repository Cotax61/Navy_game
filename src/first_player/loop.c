/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** loop
*/

#include <sys/types.h>
#include "loop.h"
#include "main.h"
#include "my.h"

int first_player_loop(char **my_map, pid_t enemy)
{
    int enemy_hp = 14;
    int my_hp = 14;
    char **enemy_map = create_map();
    int damage = 0;

    while (my_hp && enemy_hp) {
        display_pos(my_map, enemy_map);
        damage = attack(my_map, enemy);
        if (damage == -1)
            return (-1);
        enemy_hp -= damage;
        if (!enemy_hp)
            break;
        my_putstr("waiting for enemy's attack...\n");
        damage = defend(my_map, enemy);
        my_hp -= damage;
    }
    return (my_hp == 0) ? 1 : 0;
}