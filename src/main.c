/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** my_navy
*/

#include "../include/navy_function.h"

int global = 0;

void handler(int signum, siginfo_t *info, void *context)
{
    if (signum == SIGUSR2) {
        global = info->si_pid;
    }
    if (signum == SIGUSR1) {
        global = info->si_pid;
    }
}

int first_connection(int arc, char **arv,
Navy_t *navy, struct sigaction *action)
{
    if (arc == 2) {
        sigaction(SIGUSR2, action, NULL);
        pause();
        navy->playerpid2 = global;
        kill(navy->playerpid2, SIGUSR1);
        my_putstr("\nenemy connected\n");
    }
    if (arc == 3) {
        sigaction(SIGUSR1, action, NULL);
        kill(navy->playerpid2, SIGUSR2);
        usleep(1000);
        if (global != navy->playerpid2) {
            write(2, "Error: connection failed\n", 25);
            return 84;
        }
    }
}

int start_navy(int arc, char **arv, Navy_t *navy, struct sigaction action)
{
    int event = 1;
    int check = 0;

    print_pid(arc, arv, navy);
    if (first_connection(arc, arv, navy, &action) == 84)
        return 84;
    if (arc == 3)
        my_putstr("\nsuccessfully connected\n");
    print_base(arc, arv, navy);
    while (event != 0) {
        check = attack_receive(navy, arc, arv);
        print_base(arc, arv, navy);
        print_win_unwin(arc, check);
        if (check == 1 || check == 2)
            return 0;
    }
}

int main_navy(int arc, char **arv)
{
    Navy_t *navy = malloc(sizeof(Navy_t));
    struct sigaction action;
    siginfo_t *info;

    action.sa_sigaction = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_SIGINFO;
    create_map(navy, arv);
    if (arc == 2)
        read_files_pos1(navy, arv);
    if (arc == 3)
        read_files_pos2(navy, arv);
    if (navy->return_error == 84)
        return 84;
    int caca = start_navy(arc, arv, navy, action);
    if (caca == 84)
        return 84;
    if (caca == 32)
        return 32;
}

int main(int arc, char **arv)
{
    if (arc == 2 && my_strcmp(arv[1], "-h") == 0)
        flag_h();
    if (arc == 2 || arc == 3) {
        int caca = main_navy(arc, arv);
        if (caca == 84)
            return 84;
        if (caca == 32)
            return 32;
    }
    return 0;
}
