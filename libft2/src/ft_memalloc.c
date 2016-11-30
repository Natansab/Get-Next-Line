/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:21:39 by nsabbah           #+#    #+#             */
/*   Updated: 2016/11/10 20:22:28 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*str;
	int		i;

	i = 0;
	str = (void *)malloc(size * sizeof(*str));
	if (str == NULL)
		return (NULL);
	while (((char *)str)[i])
	{
		((char*)str)[i] = 0;
		i++;
	}
	return (str);
}
