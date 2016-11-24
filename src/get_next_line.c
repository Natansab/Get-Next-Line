/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:35:41 by nsabbah           #+#    #+#             */
/*   Updated: 2016/11/24 18:28:02 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

  //line = (char **)malloc(sizeof(**line) * 1);
 line[0] = (char *)malloc(sizeof(*line) * 100);
  while ((ret = read(fd, &line[0][i], BUFF_SIZE)))
  {
    line[0][i + ret] = '\0';

    j = 0;
    while (line[0][j] != '\n' && line[0][j])
        j++;
    if (line[0][j] == '\n')
    {
      line[0][j] = '\0';
      break;
    }
    i = i + ret;
  }
  printf("%s", line[0]);
  return (0);
}
