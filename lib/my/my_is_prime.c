/*
** EPITECH PROJECT, 2021
** cpoolday05 task06
** File description:
** test if prime
*/

int my_is_prime(int nb)
{
    int a = 2;

    if ((nb <= 0) || (nb == 1))
        return (0);
    while (a < (nb + 1) / 2) {
        if (nb % a == 0)
            return (0);
        a++;
    }
    return (1);
}
