/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** loop
*/

#ifndef LOOP_H_
#define LOOP_H_

#include <sys/types.h>

int attack(char **map, pid_t enemy);
int defend(char **map, pid_t pid);
char **create_map(char *file_path);

#endif /* !LOOP_H_ */