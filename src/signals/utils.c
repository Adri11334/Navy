/*
** EPITECH PROJECT, 2022
** navy
** File description:
** utils
*/

#include <signal.h>

#include "my_navy.h"
#include "my.h"

int check_error(char *statbuf)
{
    if ('A' > statbuf[0] || statbuf[0] > 'H')
        return 84;
    if ('1' > statbuf[1] || statbuf[1] > '8')
        return 84;
    return 0;
}

void signo_update(int signum, siginfo_t *siginfo, void *ptr)
{
    if (signum == SIGUSR2)
        signo = 1;
    else
        signo = 0;
    return;
}
