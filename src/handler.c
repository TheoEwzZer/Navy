/*
** EPITECH PROJECT, 2023
** navy
** File description:
** handler.c
*/

#include "navy.h"

void check_hit(int sig, siginfo_t *info, void *context)
{
    var->pause = 0;
    if (sig == SIGUSR1) {
        var->hit = 1;
        return;
    }
    if (sig == SIGUSR2) {
        var->hit = 0;
        return;
    }
}

void defense(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1)
        var->co[var->index]++;
    else if (sig == SIGUSR2)
        var->index++;
    if (var->index == 2)
        var->pause = 0;
}

void start(int sig, siginfo_t *info, void *context)
{
    var->enemy_pid = info->si_pid;
    var->pause = 0;
}
