/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#include "my.h"
#include "my_navy.h"

static void handler_host(int signum, siginfo_t *siginfo, void *ptr)
{
    if (signum == SIGUSR2) {
        signo = siginfo->si_pid;
    }
}

struct sigaction *init_sigaction(void (*hand)(int, siginfo_t *, void *))
{
    struct sigaction *sa = malloc(sizeof(struct sigaction) * 1);

    (*sa).sa_sigaction = hand;
    sigemptyset(&(sa->sa_mask));
    (*sa).sa_flags = SA_RESTART;
    (*sa).sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, sa, NULL) == -1) {
        return NULL;
    }
    if (sigaction(SIGUSR2, sa, NULL) == -1) {
        return NULL;
    }
    return sa;
}

int navy_host(navy_t *map)
{
    int pid = 0;
    char statbuf[3];
    int ret = 0;

    signo = 0;
    if (init_sigaction(handler_host) == NULL)
        return 84;
    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");
    usleep(6 * 1000000);
    if (signo == 0)
        return my_put_error("Timeout\n");
    kill(signo, SIGUSR2);
    my_printf("enemy connected\n\n");
    return gameloop_host(signo, map);
}

static void handler_client(int signum, siginfo_t *siginfo, void *ptr)
{
    if (signum == SIGUSR2 && siginfo->si_pid == signo)
        signo = 1;
}

int navy_client(char *char_pid, navy_t *map)
{
    int pid = my_getnbr(char_pid);
    int ret = 0;

    signo = pid;
    if (init_sigaction(handler_client) == NULL)
        return 84;
    my_printf("my_pid: %d\n", getpid());
    kill(pid, SIGUSR2);
    usleep(1 * 1000000);
    if (signo != 1)
        return my_put_error("Timeout\n");
    my_putstr("successfully connected\n\n");
    return gameloop_client(pid, map);
}
