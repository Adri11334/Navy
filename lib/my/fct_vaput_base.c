/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-edouard.chhang
** File description:
** fct_vaput_base
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char *my_return_base(int number, char *base)
{
    char *res;
    int i = 0;
    int len = my_strlen(base);

    if (number == 0)
        return my_memset(sizeof(int) * 2, "0");
    for (int tmp = number; tmp != 0; tmp /= len)
        i++;
    res = my_memset(sizeof(int) * (i + 1), NULL);
    i = 0;
    while (number != 0) {
        res[i] = base[number % len];
        number /= len;
        i++;
    }
    return (my_revstr(res));
}

char *vaput_oct(va_list va)
{
    unsigned int arg = va_arg(va, unsigned int);

    return (my_return_base(arg, "01234567"));
}

char *vaput_hexa(va_list va)
{
    unsigned int arg = va_arg(va, unsigned int);

    return (my_return_base(arg, "0123456789abcdef"));
}

char *vaput_xhexa(va_list va)
{
    unsigned int arg = va_arg(va, unsigned int);

    return (my_return_base(arg, "0123456789ABCDEF"));
}

char *vaput_bin(va_list va)
{
    unsigned int arg = va_arg(va, unsigned int);

    return (my_return_base(arg, "01"));
}
