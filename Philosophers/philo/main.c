/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:31:35 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/16 14:32:03 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **ags)
{
	int		being;
	t_pms	pms;
	t_phl	*phl;

	if (rationalism(ac, ags, &pms, &phl) == -1)
		return (0);
	if (genesis(&pms, phl) == -1)
		return (0);
	while (1)
	{
		being = questionning(&pms, phl);
		if (being == DEAD || being == ENOUGH)
			break ;
		else if (being == SINGLE)
		{
			single_life(0, &pms, pms.mutex, 0);
			break ;
		}	
	}
	not_to_be(&pms, phl);
	return (0);
}
