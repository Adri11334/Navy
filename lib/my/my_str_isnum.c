/*
** EPITECH PROJECT, 2021
** cpoolday06 task13
** File description:
** returns 1 if char is all num and 0 if not
*/

int my_str_isnum(char *str)
{
    int i = 0;

    if (str[0] == '\0')
        return (1);
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        ++i;
    }
    return (1);
}
