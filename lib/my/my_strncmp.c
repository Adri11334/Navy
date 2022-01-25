/*
** EPITECH PROJECT, 2021
** cpoolday06 task06
** File description:
** compare two strings lenghts
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while ((s1[i] != '\0') || (i < n)) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        (i++);
    }
    return (0);
}
