/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** loop
*/

#include <signal.h>
#include <sys/types.h>
#include <time.h>
#include "player_two_init.h"
#include "connect.h"
#include "my.h"

int has_connected(int action)
{
    static int connect = 0;

    if (action > 0)
        connect = 1;
    return (connect);
}

void valid_player(int sig)
{
    my_putstr("successfully connected\n");
    has_connected(1);
}

int send_connection(pid_t fp_pid)
{
    struct sigaction connect;
    int timeout = 0;
    struct timespec time = {1, 0.25L};

    connect.sa_handler = &valid_player;
    connect.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &connect, NULL);
    kill(fp_pid, SIGUSR1);
    while (!has_connected(0) && timeout != 3) {
        nanosleep(&time, NULL);
        timeout += 1;
    }
    if (timeout == 3)
        return (0);
    return (1);
}

int second_player(char *map_file, pid_t fp_pid)
{
    char **map = NULL;
    struct sigaction atk;

    if (!send_connection(fp_pid)) {
        my_put_error("Error: timeout, wrong PID.\n");
        return (0);
    }
    map = create_map();
    atk.sa_handler = &attack_logger;
    atk.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &atk, NULL);
    sigaction(SIGUSR2, &atk, NULL);
    second_player_loop(map, fp_pid);
}