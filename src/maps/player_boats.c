/*
** EPITECH PROJECT, 2021
** navy [WSL: Ubuntu]
** File description:
** get the boat position of the player
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_navy.h"
#include "my.h"

navy_t *create_maps(char const *filepath)
{
    navy_t *navy = my_memset(sizeof(navy_t), NULL);
    char *map = my_memset(sizeof(char) * 32, NULL);
    int file_reader;
    int file_descriptor;

    file_descriptor = open(filepath, O_RDONLY);
    file_reader = fs_open_read_file(filepath, file_descriptor, map);
    if (file_reader == 84)
        return NULL;
    if (gen_my_map(map) == NULL || gen_enemy_map() == NULL)
        return NULL;
    navy->my_map = gen_my_map(map);
    navy->enemy_map = gen_enemy_map();
    return navy;
}

int fs_open_read_file(char const *filepath, int fd, char *map)
{
    int read_status;
    int file_size;

    if (fd == -1)
        return my_put_error("404: File Not Fount.");
    read_status = read(fd, map, 32);
    close(fd);
    if (read_status == -1)
        return my_put_error("Failed to read file.");
    if (read_status < 32)
        return my_put_error("Read didn't complete the buffer");
    return fd;
}
