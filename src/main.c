/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include "my.h"
#include "main.h"

void help_message(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_position\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player. ");
    my_putstr("pid of the first player\n");
    my_putstr("\tnavy_position: file representing ");
    my_putstr("the position of the ships.\n");
}

void print_end_message(int index)
{
    if (index == 0)
        my_putstr("I won\n");
    else if (index == 1)
        my_putstr("Enemy won\n");
    else
        my_put_error("Connection lost\n");    
}

int main(int ac, char **av)
{
    int result = 0;
    int first_player_pid = 0;

    if (ac < 2) {
        help_message();
        return (84);
    } else if (ac == 2 && pre_check(av[1]) == 0)
        result = first_player(av[1]);
    else if (pre_check(av[2]) == 0 && ac == 3) {
        first_player_pid = my_getnbr(av[1]);
        if (first_player_pid <= 0)
            return (84);
        result = second_player(av[2], my_getnbr(av[1]));
    } else
        return (84);
    print_end_message(result);
    return (result);
}