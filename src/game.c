/*
** EPITECH PROJECT, 2023
** navy
** File description:
** game.c
*/

#include "navy.h"

void attack_follow(var_t *var, char *input)
{
    var->sa->sa_sigaction = check_hit;
    sigemptyset(&var->sa->sa_mask);
    sigaction(SIGUSR1, var->sa, NULL);
    sigaction(SIGUSR2, var->sa, NULL);
    var->pause = 1;
    while (var->pause)
        continue;
    write(1, input, 2);
    write(1, ": ", 2);
    if (var->hit) {
        write(1, "hit\n", 4);
        var->point_my++;
        var->enemy[input[1] - 49][input[0] - 65] = 'x';
    } else {
        write(1, "missed\n", 7);
        var->enemy[input[1] - 49][input[0] - 65] = 'o';
    }
    var->turn = 0;
}

void attack(void)
{
    char *input = NULL; size_t len = 0;
    write(1, "\nattack: ", 9);
    if (getline(&input, &len, stdin) == 3 && input[0] >= 'A' && input[0] <= 'H'
    && input[1] >= '1' && input[1] <= '8') {
        for (int i = 0; i < input[0] - 16 - '0'; i++, usleep(5000))
            kill(var->enemy_pid, SIGUSR1);
        kill(var->enemy_pid, SIGUSR2);
        usleep(5000);
        for (int i = 0; i < input[1] - '0'; i++, usleep(5000))
            kill(var->enemy_pid, SIGUSR1);
        kill(var->enemy_pid, SIGUSR2);
        attack_follow(var, input);
        return;
    }
    write(1, "wrong position", 14);
    attack();
}

void verif_hit(char *input)
{
    if (var->my[input[1] - 49][input[0] - 65] == '.'
    || var->my[input[1] - 49][input[0] - 65] == 'x') {
        write(1, "missed", 6);
        kill(var->enemy_pid, SIGUSR2);
    } else {
        write(1, "hit", 3);
        var->point_enemy++;
        var->my[input[1] - 49][input[0] - 65] = 'x';
        kill(var->enemy_pid, SIGUSR1);
    }
}

void defend(void)
{
    write(1, "\nwaiting for enemy's attack...\n", 31);
    var->sa->sa_sigaction = defense;
    sigemptyset(&var->sa->sa_mask);
    sigaction(SIGUSR1, var->sa, NULL);
    sigaction(SIGUSR2, var->sa, NULL);
    var->index = 0;
    var->co[0] = 64;
    var->co[1] = 48;
    var->pause = 1;
    while (var->pause)
        continue;
    write(1, var->co, 2);
    write(1, ": ", 2);
    verif_hit(var->co);
    var->turn = 1;
    write(1, "\n", 1);
}

int play_game(void)
{
    int print_board_flag = 1;

    while (var->point_my < 14 && var->point_enemy < 14) {
        if (print_board_flag)
            print_board();
        print_board_flag = !print_board_flag;
        if (var->turn)
            attack();
        else
            defend();
    }
    print_board();
    if (var->point_my == 14) {
        write(1, "\nI won\n", 7);
        return 0;
    }
    write(1, "\nEnemy won\n", 11);
    return 1;
}
