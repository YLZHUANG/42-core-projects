/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:19:55 by yzhuang           #+#    #+#             */
/*   Updated: 2023/05/31 22:18:33 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_lst **a)
{
	int		size;
	t_lst	*t;

	size = ft_lstsize(*a);
	if (!*a || (size < 2))
		return ;
	(*a)->next->acts = (*a)->acts;
	(*a)->acts = NULL;
	(*a)->next->tail = NULL;
	t = (*a);
	(*a) = (*a)->next;
	t->next = NULL;
	ft_lstadd_back(a, t);
	(*a)->tail = t;
	(*a)->acts = ft_strjoin((*a)->acts, "ra\n");
}

void	op_rb(t_lst **a, t_lst **b)
{
	int		size;
	t_lst	*t;

	size = ft_lstsize(*b);
	if (!*b || (size < 2))
		return ;
	(*b)->next->acts = (*b)->acts;
	(*b)->acts = NULL;
	(*b)->next->tail = NULL;
	t = (*b);
	*b = (*b)->next;
	t->next = NULL;
	ft_lstadd_back(b, t);
	(*b)->tail = t;
	(*a)->acts = ft_strjoin((*a)->acts, "rb\n");
}

void	op_rr(t_lst **a, t_lst **b)
{
	op_ra(a);
	op_rb(a, b);
	(*a)->acts = cut_join((*a)->acts, "rr\n", 6, 3);
}

void	op_rra(t_lst **a)
{
	int		size;
	t_lst	*t;
	t_lst	*new_tail;

	new_tail = NULL;
	size = ft_lstsize(*a);
	if (!*a || (size < 2))
		return ;
	t = (*a)->tail;
	new_tail = new_last(*a, t);
	ft_lstadd_front(a, t);
	(*a)->tail = new_tail;
	new_tail->next = NULL;
	(*a)->acts = (*a)->next->acts;
	(*a)->next->acts = NULL;
	(*a)->next->tail = NULL;
	(*a)->acts = ft_strjoin((*a)->acts, "rra\n");
}

void	op_rrb(t_lst **a, t_lst **b)
{
	int		size;
	t_lst	*t;
	t_lst	*new_tail;

	new_tail = NULL;
	size = ft_lstsize(*b);
	if (!*b || (size < 2))
		return ;
	t = (*b)->tail;
	new_tail = new_last(*b, t);
	ft_lstadd_front(b, t);
	(*b)->tail = new_tail;
	new_tail->next = NULL;
	(*b)->next->tail = NULL;
	(*a)->acts = ft_strjoin((*a)->acts, "rrb\n");
}
