/*
** EPITECH PROJECT, 2021
** cpoolday06 task14
** File description:
** returns 1 if char is a letter and 0 if not
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return (1);
    while (str[i] != '\0') {
        if ((str[i] <= 31) || (str[i] == 123))
            return (0);
        ++i;
    }
    return (1);
}
