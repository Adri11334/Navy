/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

#include "my_navy.h"
#include "my.h"

int navy_host(navy_t *map);
int navy_client(char *pid, navy_t *map);

volatile sig_atomic_t signo = 0;

int print_help(void)
{
    int fd = open(HELP, O_RDONLY);
    char buffer[193];

    if (read(fd, buffer, 192) != -1)
        write(1, buffer, 192);
    else
        return my_put_error("Failed to load help file\n");
    return 0;
}

int navy_main(int argc, char **argv)
{
    navy_t *navy = NULL;

    for (int i = 0; i < argc; i++)
        if (my_strcmp(argv[i], "-h") == 0)
            return print_help();
    if (argc == 1) {
        navy = create_maps(argv[0]);
        if (navy == NULL)
            return (84);
        return navy_host(navy);
    }
    if (argc == 2) {
        navy = create_maps(argv[1]);
        if (navy == NULL)
            return (84);
        return navy_client(argv[0], navy);
    }
    return my_put_error("Invalid arguments\n");
}
