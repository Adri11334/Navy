/*
** EPITECH PROJECT, 2022
** navy
** File description:
** player_shoot
*/

#include "my_navy.h"
#include "my.h"

void my_shoot_missed(navy_t *navy, char line, char col)
{
    my_printf("%c%c: missed\n\n", col, line);
    navy->enemy_map[line - '1'][(col - 'A') * 2] = 'o';
}

void my_shoot_hit(navy_t *navy, char line, char col)
{
    my_printf("%c%c: hit\n\n", col, line);
    navy->enemy_map[line - '1'][(col - 'A') * 2] = 'x';
}

void enemy_shoot_missed(navy_t *navy, int position)
{
    my_printf("%c%c: missed\n\n", position / 10 + 'A', position % 10 + '1');
    navy->my_map[position % 10][position / 10 * 2] = 'o';
}

void enemy_shoot_hit(navy_t *navy, int position)
{
    my_printf("%c%c: hit\n\n", position / 10 + 'A', position % 10 + '1');
    navy->my_map[position % 10][position / 10 * 2] = 'x';
}
