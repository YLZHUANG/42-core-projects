/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:30:23 by yzhuang           #+#    #+#             */
/*   Updated: 2023/06/16 12:18:07 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_lst **a, t_lst **b)
{
	if ((*a)->nb > (*a)->next->nb)
	{
		if ((*b) && (*b)->next && (*b)->nb < (*b)->next->nb)
			op_ss(a, b);
		else
			op_sa(a);
	}
}

void	sort_3(t_lst **a, t_lst **b, int ttl, int *tab)
{
	int	la;

	la = ft_lstsize(*a);
	if (la == 2)
	{
		sort_2(a, b);
		return ;
	}
	if (((*a)->nb == tab[ttl - 3] && (*a)->next->nb == tab[ttl - 1])
		|| ((*a)->nb == tab[ttl - 1] && (*a)->next->nb == tab[ttl - 2])
		|| ((*a)->nb == tab[ttl - 2] && (*a)->next->nb == tab[ttl - 3]))
	{
		if ((*b) && (*b)->next && (*b)->nb < (*b)->next->nb)
			op_ss(a, b);
		else
			op_sa(a);
	}
	if (ttl == 3)
	{
		if ((*a)->nb == tab[ttl - 1])
			op_ra(a);
		else if ((*a)->nb == tab[ttl - 2])
			op_rra(a);
	}
}

void	sort_more(t_lst **a, t_lst **b, int ttl, int lb)
{
	int		ts;
	t_lst	*t;

	ts = 0;
	while (lb)
	{
		t = *b;
		update_costs(a, b, ttl, lb);
		ts = 1;
		get_best(b);
		*b = t;
		do_rolling(a, b, (*b)->topush->cst);
		lb -= do_push(a, b);
	}
	if (!(lst_is_sorted(*a)))
		finalising(a, ttl, ts);
}

void	go_sorting(t_lst **a, int *tab, int ttl)
{
	int		la;
	t_lst	*b;

	la = 0;
	b = NULL;
	if (lst_is_sorted(*a) == 1)
		return ;
	ft_sort_int_tab(tab, ttl);
	if (ttl == 2 || ttl == 3)
		sort_3(a, &b, ttl, tab);
	else
	{
		update_index(a, tab, ttl);
		if ((*a)->nb == tab[ttl - 1] && lst_is_sorted((*a)->next))
		{	
			(*a)->acts = ft_strjoin((*a)->acts, "ra\n");
			return ;
		}
		devide_stk(a, &b, ttl, tab);
		la = ft_lstsize(*a);
		sort_3(a, &b, ttl, tab);
		sort_more(a, &b, ttl, ttl - la);
	}
	if (b)
		ft_clear(&b);
}
