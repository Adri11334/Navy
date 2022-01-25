/*
** EPITECH PROJECT, 2021
** navy [WSL: Ubuntu]
** File description:
** display_boats
*/

#include "my_navy.h"
#include "my.h"

void display_boats(navy_t *navy)
{
    my_putstr("my positions\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+----------------\n");
    for (int i = 0; i < 8; i++) {
        my_putchar(i + '1');
        my_putchar('|');
        my_putstr(navy->my_map[i]);
        my_putchar('\n');
    }
    my_putstr("\nenemy's positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+----------------\n");
    for (int i = 0; i < 8; i++) {
        my_putchar(i + '1');
        my_putchar('|');
        my_putstr(navy->enemy_map[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
}
