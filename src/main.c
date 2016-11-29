#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
  int fd;
    char **line;
//    int ret;
int i = 0;

    (void)argc;
    fd = open((argv[1]), O_RDONLY);
  while (i < 100)
  {
    line = (char **)malloc(sizeof(**line) * 1);
  // printf("\n          ######## Appel %i ########          \n", i);

    get_next_line(fd, line);
  //  printf("\n          ######## Fin de Appel %i ########          \n", i);
    i++;
}
}
