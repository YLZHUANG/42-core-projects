/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:15:25 by yzhuang           #+#    #+#             */
/*   Updated: 2023/06/15 16:49:20 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ok_to_go(int ac, int *tab)
{
	t_lst	*a;

	a = NULL;
	a = create_stk(tab, ac);
	go_sorting(&a, tab, ac - 1);
	ft_putstr(a->acts);
	ft_clear(&a);
}

int	main(int ac, char **ags)
{
	int	*tab;

	tab = NULL;
	if (ac < 2)
		return (0);
	check_ags(ac, ags, tab);
	tab = malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (0);
	create_tab(ac, ags, tab);
	if (is_dup(tab, ac) == 1)
		ft_exit(tab);
	if (tab_is_sorted(tab, ac))
	{
		free(tab);
		return (0);
	}
	ok_to_go(ac, tab);
	free(tab);
	return (0);
}
