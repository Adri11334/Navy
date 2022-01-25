/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-edouard.chhang
** File description:
** fct_vaput
*/

#include <stdlib.h>
#include <stdarg.h>
void my_putchar(char c);
void my_putstr(char *c);
void my_put_base(int number, char *base);
char *my_getnbr(int i);
char *my_revstr(char *c);
int my_strlen(char *s);

static void compute_oct_ascii(int number, char *dest, int *i)
{
    dest[*i] = '\\';
    for (int j = 3; j > 0; j--) {
        dest[*i + j] = number % 8 + '0';
        number /= 8;
    }
}

char *vaput_sstr(va_list va)
{
    char *arg = va_arg(va, char *);
    int j = 0;
    char *res = malloc(sizeof(char) * (my_strlen(arg) * 20) + 1);

    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] <= 31 || arg[i] >= 127) {
            res[j] = '\\';
            compute_oct_ascii(arg[i], res, &i);
            j += 4;
        } else {
            res[j] = arg[i];
            j++;
        }
    }
    return (res);
}

char *vaput_char(va_list va)
{
    char arg = va_arg(va, int);
    char *tab = malloc(sizeof(char) * 2);

    tab[0] = arg;
    return (tab);
}

char *vaput_ptr(va_list va)
{
    long int arg = (long int)va_arg(va, void *);
    char *res;
    int i = 0;
    char base[16] = "0123456789abcdef";

    for (int tmp = arg; tmp != 0; tmp /= 16)
        i++;
    res = malloc(sizeof(int) * (i + 1));
    i = 0;
    while (arg != 0) {
        res[i] = base[arg % 16];
        arg /= 16;
        i++;
    }
    res[i] = 'x';
    res[i + 1] = '0';
    return (my_revstr(res));
}
