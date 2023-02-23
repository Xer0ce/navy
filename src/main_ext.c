/*
** EPITECH PROJECT, 2023
** navy
** File description:
** main_ext
*/

#include "../include/navy_function.h"

int attack_receive(Navy_t *navy, int arc, char **arv)
{
    char *pos = NULL;
    int check = 0;

    if (arc == 2 && start_attack(arc, arv, navy, pos) == 1)
        check = 1;
    if (arc == 3 && start_receive(arc, arv, navy) == 32)
        check = 1;
    if (arc == 3 && start_attack(arc, arv, navy, pos) == 1 && check != 1)
        check = 2;
    if (arc == 2 && start_receive(arc, arv, navy) == 32 && check != 1)
        check = 2;
    return check;
}

int print_win_unwin(int arc, int check)
{
    if (arc == 2 && check == 1)
        my_putstr("\nI won\n");
    if (arc == 3 && check == 1)
        my_putstr("\nEnemy won\n");
    if (arc == 2 && check == 2)
        my_putstr("\nEnemy won\n");
    if (arc == 3 && check == 2)
        my_putstr("\nI won\n");
    return 0;
}
