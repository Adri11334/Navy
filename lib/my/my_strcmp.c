/*
** EPITECH PROJECT, 2021
** cpoolday06 task01
** File description:
** function that copies a string
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        (i++);
    }
    return (0);
}
