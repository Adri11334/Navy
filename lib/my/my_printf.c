/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-edouard.chhang
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>

void my_putstr(char *str);
void my_putchar(char c);
char *vaput_oct(va_list va);
char *vaput_dec(va_list va);
char *vaput_hexa(va_list va);
char *vaput_xhexa(va_list va);
char *vaput_bin(va_list va);
char *vaput_sstr(va_list va);
char *vaput_char(va_list va);
char *vaput_ptr(va_list va);
char *vaput_nbr(va_list va);

char *vaput_percent(va_list va)
{
    my_putchar('%');
    return "";
}

char *vaput_str(va_list va)
{
    char *arg = va_arg(va, char *);

    return (arg);
}

void handle_flag(char **str, va_list ap)
{
    char *(*put_fct[])(va_list) = {&vaput_char, &vaput_nbr, &vaput_nbr,
        &vaput_str, &vaput_sstr, &vaput_bin, &vaput_oct, &vaput_dec,
        &vaput_hexa, &vaput_xhexa, &vaput_ptr, &vaput_percent};
    char flags[] = "cdisSbouxXp%";
    for (int i = 0; i < 12; i++) {
        if (**str == flags[i]) {
            my_putstr(put_fct[i](ap));
            return;
        }
    }
    return;
}

void my_printf(char *s, ...)
{
    va_list ap;

    va_start(ap, s);
    for (; s[0] != '\0'; s = &s[1]) {
        if (s[0] == '%') {
            s = &s[1];
            handle_flag(&s, ap);
        } else
            my_putchar(s[0]);
    }
    va_end(ap);
    return;
}
