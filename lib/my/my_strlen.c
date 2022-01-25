/*
** EPITECH PROJECT, 2021
** cpoolday04 task03
** File description:
** function that counts str len
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        (i++);
    return (i);
}
