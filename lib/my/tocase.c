/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** tocase
*/

char tocase(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}