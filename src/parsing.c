/*
** EPITECH PROJECT, 2023
** navy
** File description:
** parsing.c
*/

#include "navy.h"

int init_same_digit(int letter1, int letter2, int digit1, int len)
{
    for (int i = 1; letter1 < letter2 && i < len - 1; i++) {
        if (var->my[digit1 - 1][letter1 - 1 + i] == '.')
            var->my[digit1 - 1][letter1 - 1 + i] = var->len;
        else
            return 84;
    }
    for (int i = 1; letter1 >= letter2 && i < len - 1; i++) {
        if (var->my[digit1 - 1][letter1 - 1 - i] == '.')
            var->my[digit1 - 1][letter1 - 1 - i] = var->len;
        else
            return 84;
    }
    return 0;
}

int init_same_letter(int letter1, int digit2, int digit1, int len)
{
    for (int i = 1; digit1 < digit2 && i < len - 1; i++) {
        if (var->my[digit1 - 1 + i][letter1 - 1] == '.')
            var->my[digit1 - 1 + i][letter1 - 1] = var->len;
        else
            return 84;
    }
    for (int i = 1; digit1 >= digit2 && i < len - 1; i++) {
        if (var->my[digit1 - 1 - i][letter1 - 1] == '.')
            var->my[digit1 - 1 - i][letter1 - 1] = var->len;
        else
            return 84;
    }
    return 0;
}

int init_boat(char *line)
{
    unsigned int len_line = my_strlen(line);
    if (!line || len_line != 8)
        return 84;
    var->len = line[0];
    int len = line[0] - 48;
    int letter1 = line[2] - 64, digit1 = line[3] - 48, letter2 = line[5] - 64;
    int digit2 = line[6] - 48; var->boat += len;
    if (var->my[digit1 - 1][letter1 - 1] == '.')
        var->my[digit1 - 1][letter1 - 1] = line[0];
    else
        return 84;
    if (var->my[digit2 - 1][letter2 - 1] == '.')
        var->my[digit2 - 1][letter2 - 1] = line[0];
    else
        return 84;
    if ((digit1 == digit2) && (ABS(letter2 - letter1) == len - 1))
        return init_same_digit(letter1, letter2, digit1, len);
    if ((letter1 == letter2) && (ABS(digit2 - digit1) == len - 1))
        return init_same_letter(letter1, digit2, digit1, len);
    return 84;
}

int parsing(char *pos)
{
    FILE *fp = fopen(pos, "r");
    size_t len = 0;
    char *line = NULL;
    int boat = 0;
    var->boat = 0;
    if (!fp)
        return 84;
    while (getline(&line, &len, fp) != -1) {
        boat++;
        if (init_boat(line) == 84)
            return 84;
    }
    if (var->boat != 14 || boat != 4)
        return 84;
    if (line) {
        free(line);
        line = NULL;
    }
    fclose(fp);
    return 0;
}
