/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genesis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:58 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/20 13:09:31 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *arg)
{
	int		pnb;
	t_phl	*phl;

	phl = (t_phl *)arg;
	pnb = phl->pms->pnb;
	if (pnb == 1)
	{
		single_life(1, phl->pms, phl->pms->mutex, phl->id);
		return (NULL);
	}
	if (!(phl->id % 2))
	{
		if (print_m(PT, phl->id, phl->pms))
			return (NULL);
		usleep(9000);
	}	
	living(phl, phl->pms);
	return (NULL);
}

int	genesis(t_pms *pms, t_phl *phl)
{
	int	n;

	n = 0;
	if (init_mutex(pms, phl) != 0)
		return (-1);
	pms->begin = get_time(pms->helps);
	while (n < pms->pnb)
	{
		phl[n].id = n;
		phl[n].start = 0;
		phl[n].ecount = 0;
		phl[n].pms = pms;
		phl[n].start = pms->begin;
		if (pthread_create(&(pms->thread[n]), NULL, &philo, &phl[n]) != 0)
		{
			error_management(PTH, pms, phl, n);
			return (-1);
		}
		n++;
	}
	return (0);
}
