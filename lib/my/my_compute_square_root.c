/*
** EPITECH PROJECT, 2021
** cpoolday05 task05
** File description:
** function square root
*/

int my_compute_square_root(int nb)
{
    int root = 0;

    while (root * root <= nb) {
        if ((root * root) == nb)
            return (root);
        if (root == 32768)
            return (0);
        (root++);
    }
    return (0);
}
