/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:35:41 by nsabbah           #+#    #+#             */
/*   Updated: 2016/12/07 16:38:50 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_stock2line(char **stock, char **line)
{
  int len;

  /* If there is a '\n in stock, put it in line */
  if (ft_strchr(*stock, '\n') != NULL)
  {
    len = ft_strchr(*stock, '\n') - *stock;
    line[0] = ft_strsub(*stock, 0, len);
    *stock = ft_strchr(*stock, '\n') + 1;
    return (1);
  }
  /* If there is no newline in stock, copy stock in line [0] */
  line[0] = ft_strdup(*stock);
  *stock = NULL;
  return (0);
}

int get_next_line(const int fd, char **line)
{
  int ret;
  static char *stock = NULL;
  int len;
  char *str;
  char *tmp;

  if (line == NULL)
    return (-1);
  line[0] = ft_strnew(BUFF_SIZE);
  if (stock != NULL)
 //   {
      if (ft_stock2line(&stock, &line[0]))
        return (1);
  //    stock = NULL;
   // }

  str = ft_strnew(BUFF_SIZE);
  while ((ret = read(fd, str, BUFF_SIZE)))
  {
    if (ret == -1)
      return (-1);
    str[ret] = '\0';
    tmp = ft_strdup(line[0]);
    free (line[0]);
    line[0] = ft_strjoin(tmp, str);
    free(tmp);
    if (ft_strchr(line[0], '\n') != NULL)
    {
      len = ft_strchr(line[0], '\n') - line[0];
      stock = ft_strdup(&(line[0][len + 1]));
      tmp = ft_strdup(line[0]);
      free (line[0]);
      line[0] = ft_strsub(tmp, 0, len);
      free(tmp);
      break;
    }
  }
  free(str);
  if (ret == 0 && ft_strlen(line[0]) == 0)
    return (0);
  return (1);
}
