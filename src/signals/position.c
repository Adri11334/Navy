/*
** EPITECH PROJECT, 2021
** navy
** File description:
** position
*/

#include <unistd.h>
#include <signal.h>

#include "my_navy.h"
#include "my.h"

int receive_number(int pid)
{
    int result1 = 0;
    int result2 = 0;

    for (int i = 0; i < 3; i++) {
        pause();
        usleep(0.01 * 1000000);
        result1 = result1 * 2 + (int)signo;
        kill(pid, SIGUSR2);
    }
    for (int i = 0; i < 3; i++) {
        pause();
        usleep(0.01 * 1000000);
        result2 = result2 * 2 + (int)signo;
        kill(pid, SIGUSR2);
    }
    return (result1 * 10 + result2);
}

int send_number(char *msg, int pid)
{
    int nb1 = (msg[0] - 'A');
    int nb2 = (msg[1] - '1');

    for (int i = 2; i >= 0; i--) {
        signo = 0;
        kill(pid, SIGUSR1 + (((nb1 >> i) & 1) * 2));
        pause();
        usleep(0.01 * 1000000);
    }
    for (int i = 2; i >= 0; i--) {
        signo = 0;
        kill(pid, SIGUSR1 + ((nb2 >> i) & 1) * 2);
        pause();
        usleep(0.01 * 1000000);
    }
    return 0;
}

int receiver(int pid, navy_t *map)
{
    struct sigaction sa;
    int result = 0;
    char tile_hit = 0;

    my_printf("waiting for enemy's attack\n");
    result = receive_number(pid);
    tile_hit = map->my_map[result % 10][result / 10 * 2];
    usleep(1 * 100000);
    if (tile_hit == '.') {
        enemy_shoot_missed(map, result);
        kill(pid, SIGUSR1);
    } else {
        enemy_shoot_hit(map, result);
        kill(pid, SIGUSR2);
    }
    return 0;
}

int sender(int pid, navy_t *map)
{
    struct sigaction sa;
    char statbuf[3] = "";

    my_printf("attack: ");
    read(0, statbuf, 2);
    statbuf[2] = '\0';
    if (check_error(statbuf) == 84) {
        my_putstr("wrong position\n");
        return sender(pid, map);
    }
    map->enemy_map[statbuf[1] - '1'][(statbuf[0] - 'A') * 2] = 'x';
    usleep(1 * 1000000);
    send_number(statbuf, pid);
    pause();
    if (signo == 0)
        my_shoot_missed(map, statbuf[1], statbuf[0]);
    else
        my_shoot_hit(map, statbuf[1], statbuf[0]);
    return 0;
}
