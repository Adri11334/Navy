/*
** EPITECH PROJECT, 2022
** navy
** File description:
** gameloop
*/

#include "my_navy.h"
#include "my.h"

int enemy_won(navy_t *map)
{
    display_boats(map);
    my_putstr("Enemy won\n");
    return 1;
}

int i_won(navy_t *map)
{
    display_boats(map);
    my_putstr("I won\n");
    return 0;
}

int check_victory(char **map)
{
    int nb_hits = 0;

    for (int index = 0; index < 64; index++) {
        if (map[index % 8][(index / 8) * 2] == 'x')
            nb_hits++;
    }
    if (nb_hits == 14)
        return 1;
    return 0;
}

int gameloop_client(int pid, navy_t *map)
{
    init_sigaction(signo_update);
    while (1) {
        display_boats(map);
        receiver(pid, map);
        if (check_victory(map->my_map) == 1)
            return enemy_won(map);
        sender(pid, map);
        if (check_victory(map->enemy_map) == 1)
            return i_won(map);
    }
}

int gameloop_host(int pid, navy_t *map)
{
    init_sigaction(signo_update);
    while (1) {
        display_boats(map);
        sender(pid, map);
        if (check_victory(map->enemy_map) == 1)
            return i_won(map);
        receiver(pid, map);
        if (check_victory(map->my_map) == 1)
            return enemy_won(map);
    }
}
