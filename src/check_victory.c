/*
** EPITECH PROJECT, 2023
** navy
** File description:
** check_victory
*/

#include "../include/navy_function.h"

int check_v_ext(char **map, int i, int j, int count)
{
    if (map[i][j] == 'x')
        count++;
    return count;
}

int check_victory(char **map)
{
    int count = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            count = check_v_ext(map, i, j, count);
    }
    if (count == 14)
        return 1;
    else
        return 0;
}
