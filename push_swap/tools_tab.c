/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:37:08 by yzhuang           #+#    #+#             */
/*   Updated: 2023/06/01 17:50:29 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_index(t_lst **a, int *tab, int ttl)
{
	int		i;
	t_lst	*t;

	t = *a;
	while (*a)
	{
		i = 0;
		while (i < ttl && (*a)->nb != tab[i])
			i++;
		if ((*a)->nb == tab[i])
			(*a)->i = i;
		*a = (*a)->next;
	}
	*a = t;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < (size - 1))
		{	
			if (tab[j] > tab[j + 1])
			{
				t = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = t;
			}
			j++;
		}
		i++;
	}
}

void	create_tab(int ac, char **ags, int *tab)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (i < ac)
	{
		tab[n] = stoi(ags[i], tab);
		i++;
		n++;
	}
}

int	tab_is_sorted(int *lst, int ac)
{
	int	i;

	i = 0;
	while (i + 1 < ac - 1)
	{
		if (lst[i] > lst[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	cst_to_tab(t_cst *cst, int *ct)
{
	ct[0] = 0;
	ct[1] = 0;
	while (cst->ra > 0 && cst->rb > 0)
	{
		ct[0]++;
		cst->ra--;
		cst->rb--;
	}
	while (cst->rra > 0 && cst->rrb > 0)
	{
		ct[1]++;
		cst->rra--;
		cst->rrb--;
	}
	ct[2] = cst->ra;
	ct[3] = cst->rb;
	ct[4] = cst->rra;
	ct[5] = cst->rrb;
}
