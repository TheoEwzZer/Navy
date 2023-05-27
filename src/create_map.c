/*
** EPITECH PROJECT, 2023
** navy
** File description:
** create_map.c
*/

#include "navy.h"

int create_map(void)
{
    var->my = malloc(sizeof(char *) * 9);
    var->enemy = malloc(sizeof(char *) * 9);
    var->my[8] = 0;
    var->enemy[8] = 0;
    for (int i = 0; i < 9; i++) {
        var->my[i] = malloc(sizeof(char) * 9);
        var->enemy[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 9; j++) {
            var->my[i][j] = '.';
            var->enemy[i][j] = '.';
        }
        var->my[i][8] = '\0';
        var->enemy[i][8] = '\0';
    }
    return 0;
}
