/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:14 by yzhuang           #+#    #+#             */
/*   Updated: 2023/05/30 17:34:56 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_lst *lst)
{
	int	c;

	c = 0;
	while (lst)
	{
		lst = lst->next;
		c++;
	}
	return (c);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_lst **lst, t_lst *new)
{
	if (*lst)
		new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*t;

	t = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		t = ft_lstlast(*lst);
		t->next = new;
	}
}

t_lst	*new_last(t_lst *lst, t_lst *t)
{
	while (lst && (lst->next->nb != t->nb))
		lst = lst->next;
	lst->next = NULL;
	return (lst);
}
