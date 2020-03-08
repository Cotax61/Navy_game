/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** attack
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "attack_log.h"
#include "my.h"

int check_user_input(char *input, char **map)
{
    int num = 0;
    int letter = 2 + (icase(input[0]) - 'a') * 2;

    if (input[2] != '\n' && input[2] != '\0')
        return (my_ret_message("Error: input should be 3 char long\n", 0));
    if (icase(input[0]) < 'a' || icase(input[0]) > 'h')
        return (my_ret_message("Error: first char have to be a letter\n", 0));
    input[2] = '\0';
    num = my_getnbr(input + 1) + 1;
    if (input[1] < '1' || input[1] > '8')
        return (my_ret_message("Error: second char have to be a number\n", 0));
    if (map[num][letter] == 'x' || map[num][letter] == 'o')
        return (my_ret_message("Error: wrong position\n", 0));
    return (1);
}

char *read_user_input(char **map)
{
    char *user_ipt = malloc(1);
    int size = 0;

    do {
        if (!user_ipt)
            return (NULL);
        free(user_ipt);
        if (!user_ipt)
            return (NULL);
        user_ipt = malloc(sizeof(char) * 3);
        my_putstr("Attack: ");
        size = read(0, user_ipt, 3);
        if (!size)
            return (NULL);
        lseek(0, 0, SEEK_END);
        user_ipt[2] = '\0';
    } while (!check_user_input(user_ipt, map));
    return (user_ipt);
}

int check_atk_response(char **map, int letter, int number)
{
    int response = attack_log(VALID_CHECK);

    my_putchar(letter);
    my_putchar(number + '1' - 2);
    my_putchar(':');
    my_putstr(response == -1 ? " missed\n" : " hit\n");
    map[number][letter] = response == -1 ? 'o' : 'x';
    return (response);
}

static void send_signals(pid_t enemy)
{
    kill(enemy, SIGUSR1);
    pause();
    usleep(300);
}

int attack(char **map, pid_t enemy)
{
    char *user_ipt = read_user_input(map);

    if (!user_ipt)
        return (-2);
    usleep(600);
    for (char i = 'a' - 1; i != icase(user_ipt[0]) + 1; i++)
        send_signals(enemy);
    kill(enemy, SIGUSR2);
    pause();
    usleep(300);
    for (char i = '0'; i != user_ipt[1]; i++)
        send_signals(enemy);
    usleep(300);
    kill(enemy, SIGUSR2);
    attack_log(RESET_COUNT);
    pause();
    return (check_atk_response(map, icase(user_ipt[0]) - 32,
    user_ipt[1] - '0' + 1));
}