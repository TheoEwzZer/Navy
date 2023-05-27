/*
** EPITECH PROJECT, 2023
** navy
** File description:
** print_board.c
*/

#include "navy.h"

void print_board(void)
{
    print_board_my();
    print_board_enemy();
}

void print_board_my(void)
{
    write(1, "\nmy positions:\n", 15);
    write(1, " |A B C D E F G H\n", 18);
    write(1, "-+---------------\n", 18);
    for (int i = 0; i < 8; i++) {
        my_put_nbr(i + 1, 0);
        write(1, "|", 1);
        for (int j = 0; j < 7; j++) {
            write(1, &var->my[i][j], 1);
            write(1, " ", 1);
        }
        write(1, &var->my[i][7], 1);
        write(1, "\n", 1);
    }
}

void print_board_enemy(void)
{
    write(1, "\nenemy's positions:\n", 20);
    write(1, " |A B C D E F G H\n", 18);
    write(1, "-+---------------\n", 18);
    for (int i = 0; i < 8; i++) {
        my_put_nbr(i + 1, 0);
        write(1, "|", 1);
        for (int j = 0; j < 7; j++) {
            write(1, &var->enemy[i][j], 1);
            write(1, " ", 1);
        }
        write(1, &var->enemy[i][7], 1);
        write(1, "\n", 1);
    }
}
