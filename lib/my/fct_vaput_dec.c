/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-edouard.chhang
** File description:
** fct_vaput_dec
*/

#include <stdarg.h>
char *my_return_base(int number, char *base);

char *vaput_dec(va_list va)
{
    unsigned int arg = va_arg(va, unsigned int);

    return (my_return_base(arg, "0123456789"));
}

char *vaput_nbr(va_list va)
{
    int arg = va_arg(va, int);

    return (my_return_base(arg, "0123456789"));
}
