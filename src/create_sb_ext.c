/*
** EPITECH PROJECT, 2023
** navy
** File description:
** crate_sb_ext
*/

#include "../include/navy_function.h"

int replace_by_letter(Navy_t *navy, char *pos, char **map)
{
    int letter = pos[0] - 'A';
    letter = letter * 2;
    letter += 2;
    int nbr = pos[1] - '1';
    nbr = nbr + 2;

    if (map[nbr][letter] != '.')
        map[nbr][letter] = 'x';
    else
        map[nbr][letter] = 'o';
}

int place_on_map(Navy_t *navy, char *pos, int arc)
{
    if (arc == 2)
        replace_by_letter(navy, pos, navy->player1);
    if (arc == 3)
        replace_by_letter(navy, pos, navy->player2);
}

int receive_signal_ext(char *binary, Navy_t *navy, int arc)
{
    char *coo = trans_bin_coo(binary);
    struct sigaction act;

    act.sa_sigaction = hand;
    my_putstr(coo);
    my_putstr(": ");
    check_attack(coo, navy, arc);
    place_on_map(navy, coo, arc);
    sigaction(SIGUSR2, &act, NULL);
    sigaction(SIGUSR1, &act, NULL);
    pause();
    if (global == 0) {
        return 1;
    }
    if (global == 1) {
        return 0;
    }
}

int for_receive_signal_ext(Navy_t *navy, char *binary, int index)
{
    struct sigaction act;
    act.sa_sigaction = hand;

    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    pause();
    if (global == 0) {
        binary[index] = '0';
    }
    if (global == 1) {
        binary[index] = '1';
    }
    kill(navy->playerpid2, SIGUSR1);
}
