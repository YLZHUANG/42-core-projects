/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:16:57 by yzhuang           #+#    #+#             */
/*   Updated: 2023/05/31 22:17:21 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_lst **a)
{
	int		size;
	t_lst	*t1;
	t_lst	*t2;

	size = ft_lstsize(*a);
	if (!*a || size < 2)
		return ;
	t1 = *a;
	t2 = (*a)->next;
	if (size == 2)
		(*a)->tail = *a;
	t1->next = t2->next;
	t2->next = t1;
	*a = t2;
	(*a)->acts = t1->acts;
	(*a)->tail = t1->tail;
	(*a)->acts = ft_strjoin((*a)->acts, "sa\n");
}

void	op_sb(t_lst **a, t_lst **b)
{
	int		size;
	t_lst	*t1;
	t_lst	*t2;

	size = ft_lstsize(*b);
	if (!*b || size < 2)
		return ;
	t1 = *b;
	t2 = (*b)->next;
	if (size == 2)
		(*b)->tail = *b;
	(*b)->next = t2->next;
	t2->next = t1;
	*b = t2;
	(*b)->tail = t1->tail;
	(*a)->acts = ft_strjoin((*a)->acts, "sb\n");
}

void	op_ss(t_lst **a, t_lst **b)
{
	if (!*a || !*b || !((*a)->next) ||!((*b)->next))
		return ;
	op_sa(a);
	op_sb(a, b);
	(*a)->acts = cut_join((*a)->acts, "ss\n", 6, 3);
}

void	op_pa(t_lst **a, t_lst **b)
{
	t_lst	*t;

	if (!*b)
		return ;
	if ((*b)->next)
	{
		(*b)->next->tail = (*b)->tail;
		t = (*b)->next;
		(*b)->next = NULL;
		ft_lstadd_front(a, *b);
		(*b) = t;
	}
	else
	{
		ft_lstadd_front(a, *b);
		*b = NULL;
	}
	(*a)->tail = (*a)->next->tail;
	(*a)->acts = (*a)->next->acts;
	(*a)->next->tail = NULL;
	(*a)->next->acts = NULL;
	(*a)->acts = ft_strjoin((*a)->acts, "pa\n");
}

void	op_pb(t_lst **a, t_lst **b)
{
	t_lst	*t;

	if (!*a)
		return ;
	(*a)->next->tail = (*a)->tail;
	(*a)->next->acts = (*a)->acts;
	(*a)->tail = NULL;
	(*a)->acts = NULL;
	t = (*a)->next;
	(*a)->next = NULL;
	ft_lstadd_front(b, *a);
	(*a) = t;
	if ((*b)->next)
		(*b)->tail = (*b)->next->tail;
	else
		(*b)->tail = (*b);
	(*a)->acts = ft_strjoin((*a)->acts, "pb\n");
}
