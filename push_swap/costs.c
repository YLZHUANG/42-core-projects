/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:04:39 by yzhuang           #+#    #+#             */
/*   Updated: 2023/05/30 20:57:12 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_algo(t_lst *b)
{
	int	res;

	res = 0;
	if (b->cst->rcost <= b->cst->rrcost)
	{
		if ((b->cst->ra + b->cst->rrb) < b->cst->rcost)
			res = 3;
		else if ((b->cst->rra + b->cst->rb) < b->cst->rcost)
			res = 4;
		else
			res = 1;
	}
	else
	{
		if ((b->cst->ra + b->cst->rrb) < b->cst->rrcost)
			res = 3;
		else if ((b->cst->rra + b->cst->rb) < b->cst->rrcost)
			res = 4;
		else
			res = 2;
	}
	return (res);
}

void	final_cost(t_lst **b, int dir)
{
	if (dir == 1)
	{
		(*b)->cst->cost = (*b)->cst->rcost;
		(*b)->cst->rrb = 0;
		(*b)->cst->rra = 0;
	}
	else if (dir == 2)
	{
		(*b)->cst->cost = (*b)->cst->rrcost;
		(*b)->cst->rb = 0;
		(*b)->cst->ra = 0;
	}
	else if (dir == 3)
	{
		(*b)->cst->cost = (*b)->cst->ra + (*b)->cst->rrb;
		(*b)->cst->rra = 0;
		(*b)->cst->rb = 0;
	}
	else if (dir == 4)
	{
		(*b)->cst->cost = (*b)->cst->rra + (*b)->cst->rb;
		(*b)->cst->ra = 0;
		(*b)->cst->rrb = 0;
	}
}

void	add_acost(t_lst *a, t_lst **b, int nb, int min)
{
	int	la;

	la = ft_lstsize(a);
	if (a->nb == min && nb > min)
	{
		while (a && a->nb < nb)
		{
			(*b)->cst->ra++;
			a = a->next;
		}
	}
	else
		count_ra(a, b, nb, min);
	(*b)->cst->rra = la - (*b)->cst->ra;
	if ((*b)->cst->ra > (*b)->cst->rb)
		(*b)->cst->rcost = (*b)->cst->ra;
	else
		(*b)->cst->rcost = (*b)->cst->rb;
	if ((*b)->cst->rra > (*b)->cst->rrb)
		(*b)->cst->rrcost = (*b)->cst->rra;
	else
		(*b)->cst->rrcost = (*b)->cst->rrb;
}

void	add_cost(t_lst *a, t_lst **b, int nb)
{
	int	min;
	int	algo;

	algo = 0;
	min = a_min(a);
	if ((a->nb == min && nb < min) || (nb < a->nb && nb > a->tail->nb))
	{
		if ((*b)->cst->rb <= (*b)->cst->rrb)
		{
			(*b)->cst->rrb = 0;
			(*b)->cst->cost = (*b)->cst->rb;
		}
		else
		{
			(*b)->cst->rb = 0;
			(*b)->cst->cost = (*b)->cst->rrb;
		}
		return ;
	}
	add_acost(a, b, nb, min);
	algo = get_algo(*b);
	final_cost(b, algo);
}

void	update_costs(t_lst **a, t_lst **b, int ttl, int lb)
{
	int		count;
	int		tlb;
	t_lst	*t;

	(void)ttl;
	count = 0;
	tlb = lb;
	t = *b;
	while (lb > 0)
	{
		cst_reinit((&(*b)->cst));
		(*b)->cst->rb = count;
		if (tlb > 1 && (*b)->cst->rb > 0)
			(*b)->cst->rrb = tlb - count;
		add_cost(*a, b, (*b)->nb);
		*b = (*b)->next;
		count++;
		lb--;
	}
	*b = t;
}
