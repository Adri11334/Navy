/*
** EPITECH PROJECT, 2021
** cpoolday03 task07
** File description:
** Print the number given as a parameter
*/

void my_putchar(char c);

static int my_put_nbr_recu(int c)
{
    int number = c % 10;

    if (c > 9) {
        my_put_nbr_recu(c / 10);
    } else {
        my_putchar(number + 48);
        return (0);
    }
    my_putchar(number + 48);
    return (0);
}

int my_put_nbr(int c)
{
    long a = 0;

    a = c;
    if (a < 0) {
        my_putchar('-');
        a = -1 * a;
    }
    my_put_nbr_recu(a);
    my_putchar('\n');
    return (0);
}

static int my_put_lnbr_recu(long int c)
{
    long int number = c % 10;

    if (c > 9) {
        my_put_nbr_recu(c / 10);
    } else {
        my_putchar(number + 48);
        return (0);
    }
    my_putchar(number + 48);
    return (0);
}

int my_put_lnbr(long int c)
{
    long a = 0;

    a = c;
    if (a < 0) {
        my_putchar('-');
        a = -1 * a;
    }
    my_put_nbr_recu(a);
    my_putchar('\n');
    return (0);
}
