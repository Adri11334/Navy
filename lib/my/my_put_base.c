/*
** EPITECH PROJECT, 2021
** cpoolday03 task07
** File description:
** Print the number given as a parameter
*/

#include <stdlib.h>

int my_strlen(char *str);
int my_putchar(char c);

void my_put_base(int number, char *base)
{
    int *res;
    int i = 0;
    int len = my_strlen(base);

    for (int tmp = number; tmp != 0; tmp /= len)
        i++;
    res = malloc(sizeof(int) * (i + 1));
    i = 0;
    while (number != 0) {
        res[i] = number % len;
        number /= len;
        i++;
    }
    for (i--; i >= 0; i--)
        my_putchar(base[res[i]]);
}
