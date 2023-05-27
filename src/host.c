/*
** EPITECH PROJECT, 2023
** navy
** File description:
** host.c
*/

#include "navy.h"

int host(char *pos1)
{
    var->player = 0;
    var->turn = 1;
    if (parsing(pos1) == 84)
        return 84;
    write(1, "my_pid: ", 8);
    my_put_nbr(getpid(), 0);
    write(1, "\nwaiting for enemy connection...\n", 33);
    var->pause = 1;
    var->sa->sa_sigaction = start;
    sigemptyset(&var->sa->sa_mask);
    sigaction(SIGUSR1, var->sa, NULL);
    while (var->pause)
        continue;
    write(1, "\nenemy connected\n", 17);
    return play_game();
}
