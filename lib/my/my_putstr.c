/*
** EPITECH PROJECT, 2021
** cpoolday04 task02
** File description:
** print the array located at the address given as a parameter
*/

#include <unistd.h>
void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    write(1, str, i);
}
