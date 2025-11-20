/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:41:16 by yzhuang           #+#    #+#             */
/*   Updated: 2023/05/30 16:43:34 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_min(t_lst *a)
{
	int	min;

	min = 2147483647;
	while (a)
	{
		if (a->nb < min)
			min = a->nb;
		a = a->next;
	}
	return (min);
}

void	count_ra( t_lst *a, t_lst **b, int nb, int min)
{
	if (a->nb < nb)
	{
		while (a && a->nb < nb && a->nb != min)
		{
			(*b)->cst->ra++;
			a = a->next;
		}
	}
	else
	{
		while (a && a->nb != min)
		{
			(*b)->cst->ra++;
			a = a->next;
		}
		while (a && a->nb < nb)
		{
			(*b)->cst->ra++;
			a = a->next;
		}
	}
}

int	count_bsorted(t_lst *b, int bsorted)
{
	if (b->next && b->next->i == (b->i - 1))
	{
		while (b->next && b->next->i == (b->i - 1))
		{
			bsorted++;
			b = b->next;
		}
	}
	return (bsorted);
}

int	count_last_roll(t_lst *a)
{
	int	c;

	c = 0;
	while (a && a->i != 0)
	{
		c++;
		a = a->next;
	}
	return (c);
}

void	get_best(t_lst **b)
{
	int		min;
	t_lst	*t;

	t = NULL;
	min = -1;
	(*b)->topush = *b;
	if ((*b)->cst->cost == 0)
		return ;
	t = *b;
	while (*b)
	{
		if (min < 0 || (*b)->cst->cost < min)
		{
			min = (*b)->cst->cost;
			t->topush = *b;
			if (min == 1)
				return ;
		}
		*b = (*b)->next;
	}
}
