/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:51:28 by nsabbah           #+#    #+#             */
/*   Updated: 2016/11/14 16:42:35 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*former;
	t_list	*first_elem;
	int		i;

	former = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	i = 0;
	while (lst)
	{
		tmp = lst->next;
		if (!(new = (t_list*)malloc(sizeof(*new))))
			return (NULL);
		new = f(lst);
		former->next = new;
		former = new;
		lst = tmp;
		if (i == 0)
			first_elem = new;
		i++;
	}
	return (first_elem);
}
