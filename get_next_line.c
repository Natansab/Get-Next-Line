/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:35:41 by nsabbah           #+#    #+#             */
/*   Updated: 2016/11/28 19:14:12 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int get_next_line(const int fd, char **line)
{
  static int i = 0;
  int j;
  int ret;
  static char *tmp = NULL;
  int h;
  int cut;

  line[0] = (char *)malloc(sizeof(*line) * 1000);
//  printf("\ntmp en haut vaut :\n%s\n", tmp);
  h = 0;
  // If there is already a newline in the buffer

  if (tmp != NULL)
  {
//    printf("tmp en haut vaut :\n%s|\n", tmp);
    while (tmp[h])
    {
      if (tmp[h] == '\n')
      {
        tmp[h] = '\0';
        strcpy(line[0], tmp);
    //    printf("\n|%s|\n", line[0]);
        //puts(line[0]);
    //    printf("tmp avant vaut :%s|\n", tmp);
    //    printf("h vaut %i\n", h);
        cut = strlen(&tmp[h + 1]);
        memmove(tmp, &tmp[h + 1], strlen(&tmp[h + 1]));
        tmp[cut] = '\0';
  //      printf("tmp after vaut :\n%s|\n", tmp);

        return (1);
      }
      h++;
    }
    strcpy(line [0], tmp);
    i = strlen(tmp);
  //  printf("\ni vaut : %i\n", i);
  //  printf("et line 0 vaut a moment %s|\n", line[0]);
//    puts("HELLO\n");
  }
  //line = (char **)malloc(sizeof(**line) * 1);
  while ((ret = read(fd, &line[0][i], BUFF_SIZE)))
  {
  //  printf("ret vaut : \n%i\n", ret);
    line[0][i + ret] = '\0';
  //  printf("i vaut : %i\n", i);
    j = 0;
    while (line[0][j] != '\n' && line[0][j])
    j++;
  //  printf("j vaut : %i\n", j);
    // If there is a newline in the buffer string, means should stop and return it
    if (line[0][j] == '\n')
    {
      tmp = (char *)malloc(sizeof(*tmp) * 1000);
      tmp = strdup(&(line[0][j + 1]));
    //  printf("Line[0] en avant charcutage vaut :\n|%s|\n", line[0]);
    //  printf("tmp recup du read vaut :\n|%s|\n", tmp);
      line[0][j] = '\0';
      break;
    }
    i = i + ret;
  }
//  printf("\n|%s|\n", line[0]);
//  printf("\ntmp en bas vaut :\n%s\n", tmp);
  return (1);
}
