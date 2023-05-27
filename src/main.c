/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** main
*/

#include "navy.h"

var_t *var;

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player.");
    my_putstr(" pid of the first player.\n");
    my_putstr("\tnavy_positions: file representing");
    my_putstr(" the positions of the ships.\n");
    my_putstr("created by TheoMars16 and Theo_EwzZer\n");
}

int main(int argc, char **argv)
{
    if (argc == 2 && !my_strcmp(argv[1], "-h")) {
        help();
        return 0;
    }
    var = malloc(sizeof(var_t));
    var->co = malloc(sizeof(char) * 3);
    var->co[2] = '\0';
    var->sa = malloc(sizeof(struct sigaction));
    var->point_enemy = 0, var->point_my = 0, var->sa->sa_flags = SA_SIGINFO;
    create_map();
    int ret = 0;
    if (argc == 2)
        ret = host(argv[1]);
    else if (argc == 3)
        ret = other(my_getnbr(argv[1]), argv[2]);
    else
        return 84;
    if (ret == 84)
        return 84;
    return ret;
}
