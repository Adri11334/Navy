/*
** EPITECH PROJECT, 2021
** libmy.a
** File description:
** my_put_error
*/

#include <unistd.h>

int my_strlen(char *str);

int my_put_error(char *str)
{
    write(2, str, my_strlen(str));
    return 84;
}
