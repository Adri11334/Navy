/*
** EPITECH PROJECT, 2021
** navy [WSL: Ubuntu]
** File description:
** gen_map
*/

#include <unistd.h>

#include "my_navy.h"
#include "my.h"

char **complete_map(char **map, int *positions, int i)
{
    int start_col = (positions[i] / 10) * 2;
    int end_col = (positions[i + 1] / 10) * 2;
    int start_line = (positions[i] % 10);
    int end_line = (positions[i + 1] % 10);

    if (start_col == end_col)
        for (int j = start_line - 1; j < end_line; j++)
            map[j][start_col] = (end_line + 1) - start_line + '0';
    else
        for (int j = start_col; j <= end_col; j += 2)
            map[start_line][j] = ((end_col / 2) + 1) - (start_col / 2) + '0';
    return map;
}

char **gen_my_map(char *boat)
{
    char **map = my_memset(sizeof(char *) * 10, NULL);
    int *positions = interpret_file(boat);

    if (positions == NULL)
        return (NULL);
    for (int i = 0; i < 8; i++)
        map[i] = my_memset(sizeof(char) * 16, ". . . . . . . .");
    for (int i = 0; i < 8; i += 2) {
        map = complete_map(map, positions, i);
    }
    return map;
}

char **gen_enemy_map(void)
{
    char **map = my_memset(sizeof(char *) * 8, NULL);

    for (int i = 0; i < 8; i++)
        map[i] = my_memset(sizeof(char) * 16, ". . . . . . . .");
    return map;
}
