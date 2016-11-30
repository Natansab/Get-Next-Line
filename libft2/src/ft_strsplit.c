/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:34:23 by nsabbah           #+#    #+#             */
/*   Updated: 2016/11/14 15:55:20 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	word_count(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s[i] != c)
		count = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	t_point	p;

	if (s == NULL)
		return (NULL);
	if (!(ptr = (char **)malloc(sizeof(char*) * (word_count(s, c) + 1))))
		return (NULL);
	p.i = 0;
	p.h = 0;
	while (s[p.i])
	{
		while (s[p.i] == c && s[p.i])
			p.i++;
		p.j = 0;
		while (s[p.i + p.j] != c && s[p.i + p.j])
			p.j++;
		ptr[p.h] = ft_strndup(&s[p.i], (size_t)p.j);
		p.i = p.i + p.j;
		if (p.h == word_count(s, c))
			break ;
		p.h++;
	}
	ptr[p.h] = NULL;
	return (ptr);
}
