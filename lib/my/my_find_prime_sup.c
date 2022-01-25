/*
** EPITECH PROJECT, 2021
** cpoolday05 task07
** File description:
** prints the smolst prime number >= the input
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb))
        return (nb);
    else
        return (my_find_prime_sup(nb + 1));
}
