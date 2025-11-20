/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:08:20 by yzhuang           #+#    #+#             */
/*   Updated: 2023/06/15 16:55:50 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		no_operation();
	else
		check_operations(ac, tab);
	if (tab)
		free(tab);
	return (0);
}
