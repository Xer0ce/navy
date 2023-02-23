/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** my_navy
*/

#include "../include/navy_function.h"

int check_attack(char *pos, Navy_t *navy, int arc)
{
    int letter = pos[0] - 'A';
    letter = letter * 2;
    letter += 2;
    int nbr = pos[1] - '1';
    nbr = nbr + 2;

    check_attack_ext(navy, arc, nbr, letter);
}

void hand_2(int signum, siginfo_t *info, void *context)
{
    if (signum == SIGUSR1) {
        global = 0;
        my_putstr("missed\n");
    }
    if (signum == SIGUSR2) {
        global = 1;
        my_putstr("hit\n");
    }
}

int attack(int arc, char **arv, Navy_t *navy, char *pos)
{
    size_t len = 0;
    int event = 57;
    struct sigaction act;
    act.sa_sigaction = hand_2;

    while (event != 0) {
        my_putstr("\nattack: ");
        getline(&pos, &len, stdin);
        event = intra_while(pos, navy, arc, event);
        if (event == 1)
            return 1;
    }
}
