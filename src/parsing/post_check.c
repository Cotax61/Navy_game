/*
** EPITECH PROJECT, 2020
** PSU_navy
** File description:
** post_check
*/

int calc_total_hp(char **map)
{
    int hp = 0;

    for (int i = 2; i < 8; i++)
        for (int z = 2; z < 17; z += 2)
            hp = map[i][z] < '6' && map[i][z] > '0' ? hp + 1 : hp;
    return (hp);
}

int post_check(char **map)
{
    if (calc_total_hp(map) != 14)
        return (-1);
    return (0);
}