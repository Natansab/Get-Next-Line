/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:16:10 by nsabbah           #+#    #+#             */
/*   Updated: 2016/11/14 15:56:06 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	int		start;
	int		end;

	if (s == NULL)
		return (NULL);
	start = 0;
	while ((s[start] == ' ' || s[start] == ',' || s[start] == '\n' ||
				s[start] == '\t') && s[start])
		start++;
	end = (ft_strlen(s) - 1);
	while ((s[end] == ' ' || s[end] == ',' || s[end] == '\n' || s[end] == '\t')
			&& end > 0 && end <= (int)ft_strlen(s))
		end--;
	if (end - start < 0)
		end = start;
	if (!(str = (char *)malloc(sizeof(*str) * (end - start + 2))))
		return (NULL);
	i = -1;
	while (++i <= (end - start) && end > start)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}
