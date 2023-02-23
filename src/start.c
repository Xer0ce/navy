/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** my_navy
*/

#include "../include/navy_function.h"

int start_receive(int arc, char **arv, Navy_t *navy)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    if (receive_signal(navy, arc) == 1)
        return 32;
}

int start_attack(int arc, char **arv, Navy_t *navy, char *pos)
{
    if (attack(arc, arv, navy, pos) == 1)
        return 1;
}

char *trans_coo_bin(char *coo)
{
    char *binary_code = NULL;

    binary_code = malloc(sizeof(char) * 7);
    binary_code = copy_dictio_bin(coo, binary_code);
    return binary_code;
}
