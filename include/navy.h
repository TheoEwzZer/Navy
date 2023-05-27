/*
** EPITECH PROJECT, 2022
** navy
** File description:
** navy.h
*/

#ifndef NAVY_H_

    #define NAVY_H_

    #define ABS(x) (x) < 0 ? -(x) : (x)
    #include "my.h"
    #include <signal.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <time.h>
    #include <unistd.h>

typedef struct var {
    char **enemy;
    char **my;
    char *co;
    char len;
    int boat;
    int hit;
    int index;
    int pause;
    int player;
    int point_enemy;
    int point_my;
    int turn;
    pid_t enemy_pid;
    struct sigaction *sa;
} var_t;

extern var_t *var;

int create_map(void);
int host(char *pos1);
int init_boat(char *line);
int init_same_digit(int letter1, int letter2, int digit1, int len);
int init_same_letter(int letter1, int digit2, int digit1, int len);
int other(pid_t pid, char *pos2);
int parsing(char *pos);
int play_game(void);
void attack(void);
void attack_follow(var_t *var, char *input);
void check_hit(int sig, siginfo_t *info, void *context);
void defend(void);
void defense(int sig, siginfo_t *info, void *context);
void help(void);
void print_board(void);
void print_board_enemy(void);
void print_board_my(void);
void start(int sig, siginfo_t *info, void *context);
void verif_hit(char *input);

#endif /* NAVY_H_ */
