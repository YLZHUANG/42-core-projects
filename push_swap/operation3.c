/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:23:02 by yzhuang           #+#    #+#             */
/*   Updated: 2023/06/15 16:57:36 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrr(t_lst **a, t_lst **b)
{
	op_rra(a);
	op_rrb(a, b);
	(*a)->acts = cut_join((*a)->acts, "rrr\n", 8, 4);
}

void	ft_exit(int *tab)
{
	if (tab)
		free(tab);
	write(1, "Error\n", 6);
	exit(1);
}
