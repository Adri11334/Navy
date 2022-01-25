/*
** EPITECH PROJECT, 2021
** cpoolday04 task04
** File description:
** function that reverse string
*/

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        (i++);
    return (i);
}

static void my_swap_char(char *a, char *b)
{
    char temp = *a;

    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    int str_len = my_strlen(&str[0]);
    int i = 0;

    for (i = 0; i < str_len / 2; i++)
        my_swap_char(&str[i], &str[str_len - i - 1]);
    return (str);
}
