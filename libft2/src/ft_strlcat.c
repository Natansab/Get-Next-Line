/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:10:19 by nsabbah           #+#    #+#             */
/*   Updated: 2016/11/10 20:15:07 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	h;

	h = 0;
	i = 0;
	j = ft_strlen(dst);
	while (dst[h] && h < size)
		h++;
	if (size <= h)
		return (size + ft_strlen(src));
	while (src[i] && (i + j) < size - 1)
	{
		dst[i + j] = ((char *)src)[i];
		i++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + j);
}
