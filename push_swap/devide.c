/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   devide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:43:58 by yzhuang           #+#    #+#             */
/*   Updated: 2023/05/30 17:13:05 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	keep_a(t_lst *a, int count, int mid_a)
{
	int	keep;

	keep = 0;
	while (count)
	{
		if (a->nb >= mid_a)
			keep++;
		else
			return (keep);
		count--;
		a = a->next;
	}
	return (keep);
}

void	devide_further(t_lst **a, t_lst **b, int la, int *msk)
{
	int	count;
	int	mid_a;

	count = 0;
	mid_a = 0;
	while (ft_lstsize(*a) > 3)
	{
		count = ft_lstsize(*a);
		mid_a = msk[la - (count / 2)];
		while (count)
		{
			if (keep_a(*a, count, mid_a) == count)
				break ;
			if ((*a)->nb < mid_a)
				op_pb(a, b);
			else
				op_ra(a);
			count--;
		}
	}
}

void	ft_devide_stk(t_lst **a, t_lst **b, int la, int *msk)
{
	int	mid_a;

	mid_a = msk[la / 2];
	if ((*a)->nb < mid_a)
	{
		if (la > 5 && *b && (*b)->next && ((*b)->nb < msk[la / 2 / 2])
			&& ((*b)->i != (*b)->next->i + 1))
			op_rb(a, b);
		op_pb(a, b);
	}
	else if ((*a)->nb >= mid_a)
	{
		if (*b && (*b)->next && ((*b)->nb < msk[la / 2 / 2])
			&& ((*b)->i != (*b)->next->i + 1))
			op_rr(a, b);
		else
			op_ra(a);
	}
}

void	devide_stk(t_lst **a, t_lst **b, int la, int *msk)
{
	int	mid_a;
	int	count;

	count = la;
	mid_a = msk[la / 2];
	while (count > 0)
	{
		if (keep_a(*a, count, mid_a) == count)
			break ;
		ft_devide_stk(a, b, la, msk);
		count--;
	}
	devide_further(a, b, la, msk);
}
