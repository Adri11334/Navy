/*
** EPITECH PROJECT, 2021
** cpoolday06 task08
** File description:
** puts every letter in upper case
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
        i++;
    }
    return (str);
}
