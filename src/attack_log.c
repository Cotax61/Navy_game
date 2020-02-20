/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** attack_log
*/

#include <signal.h>
#include "attack_log.h"

int attack_log(int action)
{
    static int log = 0;
    static int has_validated = 0;

    if (action == ATK_INC)
        log++;
    else if (action == ATK_VALID)
        has_validated = 1;
    if (action == RESET_COUNT) {
        log = 0;
        has_validated = 0;
    } else if (action == VALID_CHECK && has_validated == 1) {
        has_validated = 0;
        return (log);
    }
    return (-1);
}

void attack_logger(int sig)
{
    if (sig == SIGUSR1)
        attack_log(ATK_INC);
    else if (sig == SIGUSR2)
        attack_log(ATK_VALID);
}