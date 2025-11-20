/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   question.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:27:18 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/16 14:43:50 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	happy_ending(t_pms *p)
{
	long	t;

	pthread_mutex_lock(&p->helps[PRT]);
	t = get_time(p->helps);
	printf("%ld Everyone has enough eaten :) \n", t - p->begin);
	pthread_mutex_unlock(&p->helps[PRT]);
}

void	not_to_be(t_pms *pms, t_phl *phl)
{
	join_thds(pms, phl, pms->pnb);
	destroy_mtx(pms, pms->pnb);
	destroy_hps(pms, HELPS);
	cleansing(pms, phl);
}

int	find_starved(t_pms *pms, t_phl *phl, int pnb)
{
	int		n;
	long	start;

	n = 0;
	while (n < pnb)
	{
		pthread_mutex_lock(&pms->helps[START]);
		start = (phl[n]).start;
		pthread_mutex_unlock(&pms->helps[START]);
		if (get_time(pms->helps) - start >= pms->dtime)
		{
			pthread_mutex_lock(&pms->helps[END]);
			pms->end = -1;
			pthread_mutex_unlock(&pms->helps[END]);
			print_m(PD, n, pms);
			return (DEAD);
		}
		n++;
	}
	return (0);
}

int	questionning(t_pms *pms, t_phl *phl)
{
	int		pnb;
	int		t;

	pnb = pms->pnb;
	if (pnb == 1)
		return (SINGLE);
	usleep(2000);
	if (find_starved(pms, phl, pnb))
		return (DEAD);
	pthread_mutex_lock(&(pms->helps[TC]));
	t = pms->tcounts;
	pthread_mutex_unlock(&(pms->helps[TC]));
	if (pms->mcounts != -1 && t >= pnb)
	{
		pthread_mutex_lock(&(pms->helps[END]));
		pms->end = -1;
		pthread_mutex_unlock(&(pms->helps[END]));
		happy_ending(pms);
		return (ENOUGH);
	}
	return (0);
}
