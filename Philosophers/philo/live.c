/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:26:30 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/20 13:09:00 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking(t_phl *phl, t_pms *pms)
{
	pthread_mutex_lock(&(pms->helps[END]));
	if (pms->end)
	{
		pthread_mutex_unlock(&(pms->helps[END]));
		return (-1);
	}
	pthread_mutex_unlock(&(pms->helps[END]));
	if (print_m(PT, phl->id, phl->pms))
		return (-1);
	if (phl->pms->pnb % 2)
	{
		if (phl->pms->pnb < 5)
		{
			if (ft_usleep(phl->pms->etime * 800, pms))
				return (-1);
		}
		else
		{
			if (ft_usleep(phl->pms->etime * 400, pms))
				return (-1);
		}
	}
	return (0);
}

int	sleeping(t_phl *phl, t_pms *pms)
{
	pthread_mutex_lock(&(pms->helps[END]));
	if (pms->end)
	{
		pthread_mutex_unlock(&(pms->helps[END]));
		return (-1);
	}
	pthread_mutex_unlock(&(pms->helps[END]));
	if (print_m(PS, phl->id, phl->pms))
		return (-1);
	if (ft_usleep(phl->pms->stime * 1000, pms))
		return (-1);
	return (0);
}

int	lh_eating(t_pms *pms, t_phl *phl, pthread_mutex_t *mutex, int n)
{
	if (lf(pms, mutex, n))
		return (-1);
	if (rf(pms, mutex, n))
	{
		pms->fork[n] = 0;
		pthread_mutex_unlock(&mutex[n]);
		return (-1);
	}
	if (print_m(PE, n, pms))
	{
		pms->fork[(n + 1) % pms->pnb] = 0;
		pthread_mutex_unlock(&mutex[(n + 1) % pms->pnb]);
		pms->fork[n] = 0;
		pthread_mutex_unlock(&mutex[n]);
		return (-1);
	}	
	if (lh_eat(phl->pms, phl, phl->pms->mutex, phl->id))
		return (-1);
	return (0);
}

int	eating(t_phl *phl)
{
	if (phl->id + 1 == phl->pms->pnb)
	{
		if (rh_eating(phl->pms, phl, phl->pms->mutex, phl->id))
			return (-1);
	}
	else
	{
		if (lh_eating(phl->pms, phl, phl->pms->mutex, phl->id))
			return (-1);
	}
	return (0);
}

void	living(t_phl *phl, t_pms *pms)
{
	pthread_mutex_lock(&(pms->helps[END]));
	while (!pms->end && phl->ecount != -1)
	{
		pthread_mutex_unlock(&(pms->helps[END]));
		if (eating(phl))
			return ;
		phl->ecount++;
		if (pms->mcounts != -1 && phl->ecount == pms->mcounts)
		{
			phl->ecount = -1;
			pthread_mutex_lock(&(pms->helps[TC]));
			pms->tcounts++;
			pthread_mutex_unlock(&(pms->helps[TC]));
			return ;
		}
		if (sleeping(phl, pms))
			return ;
		if (thinking(phl, pms))
			return ;
		pthread_mutex_lock(&(pms->helps[END]));
	}
	pthread_mutex_unlock(&(pms->helps[END]));
}
