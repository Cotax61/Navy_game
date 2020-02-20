/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_getpid
*/

#include <sys/types.h>
#include "my.h"

int check_str(char *str)
{
    int i = 0;

    if (str[0] == '-')
        return (-1);
    while (str[i] != '\0') {
        if (str[i] < 48 || str[i] > 57)
            return (-2);
        else if (str[i] == '.')
            return (-2);
        i++;
    }
    return (1);
}

pid_t my_getpid(char *str)
{
    int i = 0;
    int exit_status = check_str(str);
    int mult = 1;
    int result = 0;

    if (exit_status != 1)
        return (exit_status);
    i = my_strlen(str) - 1;
    while (i >= 0) {
        result = result + ((str[i] - 48) * mult);
        mult *= 10;
        i--;
    }
    return (result);
}