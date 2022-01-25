/*
** EPITECH PROJECT, 2021
** cpoolday06 task08
** File description:
** puts every letter in upper case
*/

static int is_number(char c)
{
    if (c <= 57 && c >= 48)
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int cap = 1;

    while (str[i] != '\0') {
        if ((str[i] >= 97 && str[i] <= 122) && cap == 1)
            str[i] = str[i] - 32;
        if ((str[i] >= 65 && str[i] <= 90) && cap == 0)
            str[i] = str[i] + 32;
        cap = 0;
        if (str[i] == 32 || str[i] == 43 || str[i] == 45)
            cap = 1;
        ++i;
    }
    return (str);
}
