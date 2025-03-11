#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *read_map_file(const char *filename)
{
    int fd;
    static char buffer[64000];  // Static buffer with a large size
    ssize_t bytes_read;

    // Open the file
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return NULL;
    }

    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1)
    {
        perror("Error reading file");
        close(fd);
        return NULL;
    }

    // Null-terminate the map data
    buffer[bytes_read] = '\0';
    close(fd);

    return buffer;
}
