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
int i = 0;

    (void)argc;
  while (i < 200)
  {
    line = (char **)malloc(sizeof(**line) * 1);
//    printf("\n          ######## Appel %i ########          \n", i);

    get_next_line(open(argv[1], O_RDONLY), line);
//    printf("\n          ######## Fin de Appel %i ########          \n", i);
    i++;
}
}
