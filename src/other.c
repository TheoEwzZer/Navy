/*
** EPITECH PROJECT, 2023
** navy
** File description:
** other.c
*/

#include "navy.h"

int other(pid_t pid, char *pos2)
{
    var->player = 1;
    var->turn = 0;
    create_map();
    if (parsing(pos2) == 84)
        return 84;
    write(1, "my_pid: ", 8);
    my_put_nbr(getpid(), 0);
    if (kill(pid, SIGUSR1) == 0) {
        write(1, "\nsuccessfully connected\n", 24);
        var->enemy_pid = pid;
    } else {
        return 84;
    }
    return play_game();
}
