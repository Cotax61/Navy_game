/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_int_error
*/

#include <unistd.h>
#include "my.h"

int my_ret_message(char *str, int ret)
{
    write(1, str, my_strlen(str));
    return (ret);
}