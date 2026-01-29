#ifndef GNL
#define GNL
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <aio.h>
#include <string.h>

char *get_next_line(int fd);
#endif
