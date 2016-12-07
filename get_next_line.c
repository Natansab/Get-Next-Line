/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:35:41 by nsabbah           #+#    #+#             */
/*   Updated: 2016/12/07 18:32:21 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_stock2line(char **stock, char **line)
{
	int len;

	if (ft_strchr(*stock, '\n') != NULL)
	{
		len = ft_strchr(*stock, '\n') - *stock;
		line[0] = ft_strsub(*stock, 0, len);
		*stock = ft_strchr(*stock, '\n') + 1;
		return (1);
	}
	line[0] = ft_strdup(*stock);
	*stock = NULL;
	return (0);
}

int	read_f(char **line, const int fd, char **stock, char *str)
{
	char	*tmp;
	int		len;
	int		ret;

	while ((ret = read(fd, str, BUFF_SIZE)))
	{
		if (ret == -1)
			return (ret);
		str[ret] = '\0';
		tmp = ft_strdup(line[0]);
		free(line[0]);
		line[0] = ft_strjoin(tmp, str);
		free(tmp);
		if (ft_strchr(line[0], '\n'))
		{
			len = ft_strchr(line[0], '\n') - line[0];
			*stock = ft_strdup(ft_strchr(line[0], '\n') + 1);
			tmp = ft_strdup(line[0]);
			free(line[0]);
			line[0] = ft_strsub(tmp, 0, len);
			free(tmp);
			break ;
		}
	}
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*stock = NULL;
	char		*str;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	line[0] = ft_strnew(BUFF_SIZE);
	if (stock != NULL)
		if (ft_stock2line(&stock, &line[0]))
			return (1);
	str = ft_strnew(BUFF_SIZE);
	if ((ret = read_f(&line[0], fd, &stock, str)) == -1)
		return (-1);
	free(str);
	if (ret == 0 && ft_strlen(line[0]) == 0)
		return (0);
	return (1);
}
