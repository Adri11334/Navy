/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_file
*/

#include <stddef.h>

#include "my.h"
#include "my_navy.h"

static int check_letter(char letter)
{
    if ('A' < letter && letter > 'H')
        return 84;
    else
        return 0;
}

static int check_number(char number)
{
    if ('1' < number && number > '8')
        return 84;
    else
        return 0;
}

static int get_pos(char *str)
{
    int sum = 0;

    if (check_letter(str[0]) == 84 || check_number(str[1]) == 84)
        return -1;
    sum = 10 * (str[0] - 'A') + (str[1] - '0');
    return sum;
}

int *interpret_file(char *str)
{
    const char example[] = "2:**:**\n3:**:**\n4:**:**\n5:**:**\n";
    int *dest = my_memset(sizeof(int) * 8, NULL);
    int sum = 0;

    for (int i = 0; i < 32; i++)
        if (example[i] != '*' && example[i] != str[i]) {
            my_put_error("Invalid file format\n");
            return NULL;
        }
    for (int j = 0; j < 4; j++) {
        dest[2 * j] = get_pos(&str[8 * j + 2]);
        if (sum == -1)
            return NULL;
        dest[2 * j + 1] = get_pos(&str[8 * j + 5]);
        if (sum == -1)
            return NULL;
    }
    return dest;
}
