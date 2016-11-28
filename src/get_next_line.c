/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:35:41 by nsabbah           #+#    #+#             */
/*   Updated: 2016/11/28 16:50:28 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
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

  line[0] = (char *)malloc(sizeof(*line) * 1000);
//  printf("\ntmp en haut vaut :\n%s\n", tmp);
  h = 0;
  // If there is already a newline in the buffer

  if (tmp != NULL)
  {
    while (tmp[h])
    {
      if (tmp[h] == '\n')
      {
        tmp[h] = '\0';
        strcpy(line[0], tmp);
        //printf("\nline[0] au milieu vaut :\n%s\n", line[0]);
        puts(line[0]);
        memcpy(tmp, &tmp[h + 1], strlen(&tmp[h + 1]));
        return (0);
      }
      h++;
    }
    strcpy(line [0], tmp);
    i = strlen(tmp);
    puts("HELLOOOOO");
  }
  //line = (char **)malloc(sizeof(**line) * 1);
  while ((ret = read(fd, &line[0][i], BUFF_SIZE)))
  {
  //  printf("ret vaut : \n%i\n", ret);
    line[0][i + ret] = '\0';

    j = 0;
    while (line[0][j] != '\n' && line[0][j])
    j++;
    // If there is a newline in the buffer string, means should stop and return it
    if (line[0][j] == '\n')
    {
      tmp = (char *)malloc(sizeof(*tmp) * 1000);
      tmp = strdup(&(line[0][j + 1]));
      line[0][j] = '\0';
      break;
    }
    i = i + ret;
  }
  printf("\nLine [0] en bas vaut :\n%s", line[0]);
//  printf("\ntmp en bas vaut :\n%s\n", tmp);
  return (0);
}
