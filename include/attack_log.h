/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** ATTACK_LOG
*/

#ifndef ATTACK_LOG_H_
#define ATTACK_LOG_H_

int attack_log(int action);

enum atk_log_act {
    ATK_INC = 0,
    ATK_VALID = 1,
    RESET_COUNT = 2,
    VALID_CHECK = 3,
};

#endif /* !ATTACK_LOG_H_ */