/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** defend
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "attack_log.h"
#include "my.h"

void display_atk_pos(int row, int col)
{
    my_putchar((col/2) + 'A');
    my_putchar(row + '0' - 1);
    my_putstr(": ");
}

int get_shot_pos(pid_t enemy)
{
    int pos = -1;

    attack_log(RESET_COUNT);
    while (pos == -1) {
        pause();
        pos = attack_log(VALID_CHECK);
        kill(enemy, SIGUSR1);
    }
    return (pos);
}

int defend(char **map, pid_t pid)
{
    int number = get_shot_pos(pid);
    int letter = 0;
    int hit = 0;

    if (!number)
        return (-1);
    letter = get_shot_pos(pid) * 2;
    if (!letter)
        return (-1);
    hit = map[number][letter] != '.' ? 1 : 0;
    kill (pid, hit ? SIGUSR2 : SIGUSR1);
    display_atk_pos(number, letter);
    if (map[number][letter] != '.') {
        map[number][letter] = 'x';
        my_putstr("hit\n");
    } else {
        map[number][letter] = 'o';
        my_putstr("missed\n");
    }
    return (hit);
}