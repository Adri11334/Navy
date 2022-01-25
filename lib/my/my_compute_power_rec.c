/*
** EPITECH PROJECT, 2021
** cpoolday05 task04
** File description:
** power function recu
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p > 0)
        return (my_compute_power_rec(nb, p - 1) * nb);
    else
        return (1);
}
