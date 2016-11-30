/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:35:41 by nsabbah           #+#    #+#             */
/*   Updated: 2016/11/30 16:21:02 by nsabbah          ###   ########.fr       */
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
  int i;
  int j;
  int ret;
  static char *tmp = NULL;
  int h;

  i = 0;
  h = 0;
  if(!(line[0] = (char *)malloc(sizeof(*line) * 1000)))
    return (0);
  // If there is stuff in the tmp var
  if (tmp != NULL)
  {
    while (tmp[h])
    {
      if (tmp[h] == '\n')
      {
        tmp[h] = '\0';
   //     line[0] = strdup(tmp);
        strcpy(line[0], tmp);
        // Copy 1 more char to include the '\0' at the end of tmp[h + 1]
        memmove(tmp, &tmp[h + 1], strlen(&tmp[h + 1]) + 1);
        return (1);
      }
      h++;
    }
    // If there is no newline in tmp, copy tmp in line [0]
    strcpy(line [0], tmp);
    i = strlen(tmp);
    tmp = NULL;
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
    if (line[0][j] == '\n')
    {
      // No need to malloc tmp since strdup does it
      tmp = strdup(&(line[0][j + 1]));
      line[0][j] = '\0';
      break;
    }
    i = i + ret;
  }
  if (ret == 0 && strlen(line[0]) == 0)
    return (0);
  return (1);
}
