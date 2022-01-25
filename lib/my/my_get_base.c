/*
** EPITECH PROJECT, 2021
** libmy.a
** File description:
** Print the number given as a parameter
*/

#include <stdlib.h>

int my_strlen(char *str);
int my_putchar(char c);

int my_get_base(char *number, char *base)
{
    int sum = 0;
    int j = 0;
    int len_nb = my_strlen(number);
    int len_base = my_strlen(base);

    if (number == NULL)
        return -1;
    for (int i = 0; i < len_nb; i++) {
        for (j = 0; base[j] != number[i] && base[j] != '\0'; j++);
        if (base[j] == number[i]) {
            sum = sum * len_base + j;
        } else
            return -1;
    }
    return sum;
}
