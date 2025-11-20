/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:44:56 by yzhuang           #+#    #+#             */
/*   Updated: 2023/05/30 22:46:07 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rolling(t_lst **a, t_lst **b, t_cst *cst)
{
	int	*ct;

	ct = malloc(sizeof(int) * 6);
	if (!ct)
		return ;
	cst_to_tab(cst, ct);
	while (ct[0]--)
		op_rr(a, b);
	while (ct[1]--)
		op_rrr(a, b);
	while (ct[2]--)
		op_ra(a);
	while (ct[3]--)
		op_rb(a, b);
	while (ct[4]--)
		op_rra(a);
	while (ct[5]--)
		op_rrb(a, b);
	free(ct);
}

int	do_push(t_lst **a, t_lst **b)
{
	int	t;
	int	bsorted;

	bsorted = 1;
	bsorted = count_bsorted(*b, bsorted);
	t = bsorted;
	bsorted--;
	while (bsorted)
	{
		op_pa(a, b);
		bsorted--;
	}
	op_pa(a, b);
	return (t);
}

void	finalising(t_lst **a, int ttl, int ts)
{
	ts = count_last_roll(*a);
	if (ttl - ts < ts)
	{
		ts = ttl - ts;
		while (ts)
		{
			op_rra(a);
			ts--;
		}
	}
	else
	{
		while (ts)
		{
			op_ra(a);
			ts--;
		}
	}
}
