/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy header
*/

#ifndef MY_NAVY_H_
    #define MY_NAVY_H_

    #include <signal.h>

    #define HELP "src/assets/help.txt"

    extern volatile sig_atomic_t signo;

    typedef struct navy_s {
        char **my_map;
        char **enemy_map;
    } navy_t;

    navy_t *create_maps(char const *filepath);
    int fs_open_read_file(char const *filepath, int fd, char *map);
    char **gen_my_map(char *boat);
    char **gen_enemy_map(void);
    void display_boats(navy_t *navy);
    int *interpret_file(char *str);
    struct sigaction *init_sigaction(void (*hand)(int, siginfo_t *, void *));
    int receiver(int pid, navy_t *map);
    int sender(int pid, navy_t *map);
    int gameloop_host(int pid, navy_t *map);
    int gameloop_client(int pid, navy_t *map);
    int check_error(char *statbuf);
    void signo_update(int signum, siginfo_t *siginfo, void *ptr);
    void my_shoot_missed(navy_t *navy, char line, char col);
    void my_shoot_hit(navy_t *navy, char line, char col);
    void enemy_shoot_missed(navy_t *navy, int position);
    void enemy_shoot_hit(navy_t *navy, int position);
#endif
