/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** icase
*/

char icase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}