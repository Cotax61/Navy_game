/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_put_array
*/

#include <unistd.h>
#include "my.h"

void my_put_array(char **array, int line_jump, int end_jump)
{
    for (int i = 0; array[i]; i++) {
        write(1, array[i], my_strlen(array[i]));
        if (line_jump)
            write(1, "\n", 1);
    }
    if (end_jump)
        write(1, "\n", 1);
}