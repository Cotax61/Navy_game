/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** connect
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "connect_action.h"
#include "my.h"

pid_t connect_note_book(char action, int info)
{
    static pid_t pid = 0;

    if (action == SET_PID)
        pid = info;
    else if (action == GET_PID)
        return (pid);
    return (0);
}

void connect_handler(int sig, siginfo_t *info, void *ucontext)
{
    my_putstr("\nenemy connected\n");
    connect_note_book(SET_PID, (int)info->si_pid);
}

pid_t get_connection(void)
{
    struct sigaction connect;

    my_putstr("my_pid: ");
    my_put_nbr((int)getpid());
    my_putstr("\nwaiting for enemy connection...\n");
    connect.sa_sigaction = &connect_handler;
    connect.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &connect, NULL);
    pause();
    return (connect_note_book(GET_PID, 0));
}

int first_player(char *map_path)
{
    pid_t second_pid;

    second_pid = get_connection();
    kill(second_pid, SIGUSR1);
}