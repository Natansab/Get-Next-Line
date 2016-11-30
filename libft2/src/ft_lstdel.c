/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:56:31 by nsabbah           #+#    #+#             */
/*   Updated: 2016/11/14 16:10:40 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmplst;
	t_list *lst;

	lst = *alst;
	while (lst)
	{
		tmplst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = tmplst;
	}
	*alst = NULL;
}
