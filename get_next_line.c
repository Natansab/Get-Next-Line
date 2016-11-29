/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:35:41 by nsabbah           #+#    #+#             */
/*   Updated: 2016/11/29 18:52:21 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
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
  h = 0;
  // If there is already a newline in the buffer
  if (tmp != NULL)
  {
    while (tmp[h])
    {
      if (tmp[h] == '\n' || tmp[h] == '\0')
      {
        tmp[h] = '\0';
        strcpy(line[0], tmp);
    //    printf("\n|%s|\n", line[0]);
        cut = strlen(&tmp[h + 1]);
        memmove(tmp, &tmp[h + 1], strlen(&tmp[h + 1]));
        tmp[cut] = '\0';
        return (1);
      }
      h++;
    }
    strcpy(line [0], tmp);
    i = strlen(tmp);
  }

  while ((ret = read(fd, &line[0][i], BUFF_SIZE)))
  {
    if (ret == -1)
      return (-1);
    line[0][i + ret] = '\0';
    j = 0;
    while (line[0][j] != '\n' && line[0][j])
    j++;
    // If there is a newline in the buffer string, means should stop and return it
    if (line[0][j] == '\n' || line[0][j] == '\0')
    {
      tmp = (char *)malloc(sizeof(*tmp) * 1000);
      tmp = strdup(&(line[0][j + 1]));
      line[0][j] = '\0';
      break;
    }
    i = i + ret;
  }
  if (ret == 0)
    return (0);
//  printf("\nRet vaut %i et |%s|\n", ret, line[0]);
  return (1);
}
