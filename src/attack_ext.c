/*
** EPITECH PROJECT, 2023
** navy
** File description:
** attack_ext
*/

#include "../include/navy_function.h"

int attack_ext_arc_2 (Navy_t *navy, int nbr, int letter, int arc)
{
    struct sigaction act;
    act.sa_sigaction = hand_2;

    if (arc == 2) {
        sigaction(SIGUSR2, &act, NULL);
        sigaction(SIGUSR1, &act, NULL);
        pause();
        if (global == 0)
            navy->player1_nmi[nbr][letter] = 'o';
        else
            navy->player1_nmi[nbr][letter] = 'x';
        if (check_victory(navy->player1_nmi) == 1) {
            kill(navy->playerpid2, SIGUSR1);
            return 1;
        } else {
            kill(navy->playerpid2, SIGUSR2);
        }
    }
}

int attack_ext_arc_3 (Navy_t *navy, int nbr, int letter, int arc)
{
    struct sigaction act;
    act.sa_sigaction = hand_2;

    if (arc == 3) {
        sigaction(SIGUSR2, &act, NULL);
        sigaction(SIGUSR1, &act, NULL);
        pause();
        if (global == 0)
            navy->player2_nmi[nbr][letter] = 'o';
        else
            navy->player2_nmi[nbr][letter] = 'x';
        if (check_victory(navy->player2_nmi) == 1) {
            kill(navy->playerpid2, SIGUSR1);
            return 1;
        } else {
            kill(navy->playerpid2, SIGUSR2);
        }
    }
}

int check_attack_ext(Navy_t *navy, int arc, int nbr, int letter)
{
    if (arc == 3) {
        if (navy->player2[nbr][letter] == '.') {
            kill(navy->playerpid2, SIGUSR1);
            my_putstr("missed\n");
        } else {
            kill(navy->playerpid2, SIGUSR2);
            my_putstr("hit\n");
        }
    }
    if (arc == 2) {
        if (navy->player1[nbr][letter] == '.') {
            kill(navy->playerpid2, SIGUSR1);
            my_putstr("missed\n");
        } else {
            kill(navy->playerpid2, SIGUSR2);
            my_putstr("hit\n");
        }
    }
}

int attack_ext_check_validpos(Navy_t *navy, int arc, char *pos)
{
    char *binary_code = malloc(sizeof(char) * 7);
    int letter = pos[0] - 'A';
    letter = letter * 2;
    letter += 2;
    int nbr = pos[1] - '1';
    nbr = nbr + 2;
    int return_o = 0;

    binary_code = trans_coo_bin(pos);
    send_signal(binary_code, navy->playerpid2);
    write(1, pos, 2);
    my_putstr(": ");
    if (attack_ext_arc_2(navy, nbr, letter, arc) == 1)
        return 1;
    if (attack_ext_arc_3(navy, nbr, letter, arc) == 1)
        return 1;
}

int intra_while(char *pos, Navy_t *navy, int arc, int event)
{
    if (pos[0] >= 65 && pos[0] <= 72 && pos[1] >= 49 && pos[1] <= 56) {
        if (attack_ext_check_validpos(navy, arc, pos) == 1)
            return 1;
        event = 0;
    } else {
        my_putstr("wrong position");
        return 57;
    }
    return 0;
}
