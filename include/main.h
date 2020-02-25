/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <sys/types.h>

int first_player(char *map_path);
int second_player(char *map_file, pid_t fp_pid);
char **my_str_split(char *str, char sep);
char *my_split_cpy(char *dest, char const *src, char sep);
char **place_navy(char *filename, char **map);
char *seek_n_read(char *filepath);
void display_pos(char **map1, char **map2);
int pre_check(char *filepath);
int post_check(char **map);

#endif /* !MAIN_H_ */