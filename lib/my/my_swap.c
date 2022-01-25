/*
** EPITECH PROJECT, 2021
** cpoolday04 task01
** File description:
** swap two variables
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
