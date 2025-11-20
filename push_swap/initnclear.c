/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initnclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:13:19 by yzhuang           #+#    #+#             */
/*   Updated: 2023/05/30 17:15:04 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cst_init(t_cst **cst)
{
	(*cst) = malloc(sizeof(t_cst));
	(*cst)->ra = 0;
	(*cst)->rb = 0;
	(*cst)->rra = 0;
	(*cst)->rrb = 0;
	(*cst)->rcost = 0;
	(*cst)->rrcost = 0;
	(*cst)->cost = -1;
}

void	cst_reinit(t_cst **cst)
{
	(*cst)->ra = 0;
	(*cst)->rb = 0;
	(*cst)->rra = 0;
	(*cst)->rrb = 0;
	(*cst)->rcost = 0;
	(*cst)->rrcost = 0;
	(*cst)->cost = -1;
}

void	lst_init(t_lst **lst, int nb, t_cst *cst)
{
	(*lst) = malloc(sizeof(t_lst));
	if (!(*lst))
		return ;
	(*lst)->i = 0;
	(*lst)->nb = nb;
	(*lst)->tail = NULL;
	(*lst)->next = NULL;
	(*lst)->acts = NULL;
	(*lst)->cst = cst;
}

t_lst	*create_stk(int *tab, int ac)
{
	int		i;
	t_lst	*a;
	t_lst	*new;
	t_cst	*cst;

	i = 0;
	a = NULL;
	new = NULL;
	cst = NULL;
	while (i < (ac - 1))
	{
		cst_init(&cst);
		lst_init(&new, tab[i], cst);
		ft_lstadd_back(&a, new);
		i++;
	}
	if (new)
		a->tail = new;
	return (a);
}

void	ft_clear(t_lst **lst)
{
	t_lst	*t;

	t = NULL;
	if (lst)
	{
		if ((*lst)->acts)
			free((*lst)->acts);
		while (*lst)
		{
			t = (*lst)->next;
			free((*lst)->cst);
			free(*lst);
			*lst = t;
		}
	}
	*lst = NULL;
}
