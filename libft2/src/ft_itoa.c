/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:43:31 by nsabbah           #+#    #+#             */
/*   Updated: 2016/11/11 17:26:48 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int				size;
	int				neg;
	char			*str;
	unsigned int	nb;

	neg = (n < 0) ? 1 : 0;
	nb = (n < 0) ? -n : n;
	size = 1;
	while (n /= 10)
		size++;
	if (!(str = (char *)malloc(sizeof(*str) * (size + neg + 1))))
		return (NULL);
	str[size++ + neg] = '\0';
	while (size--)
	{
		str[size + neg - 1] = nb % 10 + '0';
		nb /= 10;
	}
	str[0] = (neg) ? '-' : str[0];
	return (str);
}
