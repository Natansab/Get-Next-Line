/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:35:41 by nsabbah           #+#    #+#             */
/*   Updated: 2016/12/06 19:44:41 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_tmp2line(char **tmp, char **line)
{
  int len;

  /* If there is a '\n in tmp, put it in line */
  if (strchr(*tmp, '\n') != NULL)
  {
    len = strchr(*tmp, '\n') - *tmp;
    line[0] = ft_strsub(*tmp, 0, len);
    *tmp = strchr(*tmp, '\n') + 1;
    return (1);
  }
  /* If there is no newline in tmp, copy tmp in line [0] */
  line[0] = strdup(*tmp);
  *tmp = NULL;
  return (0);
}

int get_next_line(const int fd, char **line)
{
  int ret;
  static char *tmp = NULL;
  int len;
  char *str;

  if (line == NULL)
    return (-1);
  /* Why do I need to malloc line[0] ?*/
  line[0] = (char *)malloc(1);

  if (tmp != NULL)
    if (ft_tmp2line(&tmp, &line[0]))
      return (1);

  str = (char *)malloc(BUFF_SIZE);
  while ((ret = read(fd, str, BUFF_SIZE)))
  {
    if (ret == -1)
      return (-1);
    str[ret] = '\0';
    line[0] = ft_strjoin(line[0], str);
    if (strchr(line[0], '\n') != NULL)
    {
      len = strchr(line[0], '\n') - line[0];
      tmp = strdup(&(line[0][len + 1]));
      line[0][len] = '\0';
      break;
    }
  }
  free(str);
  if (ret == 0 && strlen(line[0]) == 0)
    return (0);
  return (1);
}
