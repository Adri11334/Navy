/*
** EPITECH PROJECT, 2021
** cpoold04 task05
** File description:
** function that reproduces strstr
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n);

static int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        (i++);
    return (i);
}

static int is_strequal(char *str, const char *mirror)
{
    int i = 0;

    while (i < my_strlen2(mirror)) {
        if (str[i] != mirror[i])
            return (0);
        i++;
    }
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    if (my_strlen2(str) < my_strlen2(to_find))
        return (NULL);
    if (is_strequal(str, to_find))
        return (str);
    return (my_strstr(&str[1], to_find));
}
