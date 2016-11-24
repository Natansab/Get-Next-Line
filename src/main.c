#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
  //  int fd;
    char **line;
//    int ret;

    (void)argc;
    line = (char **)malloc(sizeof(**line) * 1);
    get_next_line(open(argv[1], O_RDONLY), line);
    printf("\n");
    get_next_line(open(argv[1], O_RDONLY), line);
    printf("\n");
    get_next_line(open(argv[1], O_RDONLY), line);
    printf("\n");
 }
