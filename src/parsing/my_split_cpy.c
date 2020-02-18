/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_split_cpy
*/

char *my_split_cpy(char *dest, char const *src, char sep)
{
    int i = 0;

    for (i = 0; src[i] && src[i] != sep; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}