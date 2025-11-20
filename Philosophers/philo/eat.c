/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:27:51 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/16 19:22:15 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	rf(t_pms *pms, pthread_mutex_t *mutex, int n)
{
	pthread_mutex_lock(&(pms->helps[END]));
	if (pms->end)
	{
		pthread_mutex_unlock(&(pms->helps[END]));
		return (-1);
	}
	pthread_mutex_unlock(&(pms->helps[END]));
	pthread_mutex_lock(&mutex[(n + 1) % pms->pnb]);
	pms->fork[(n + 1) % pms->pnb] = 1;
	if (print_m(PF, n, pms))
	{
		pthread_mutex_unlock(&mutex[(n + 1) % pms->pnb]);
		return (-1);
	}
	return (0);
}

int	lf(t_pms *pms, pthread_mutex_t *mutex, int n)
{
	pthread_mutex_lock(&(pms->helps[END]));
	if (pms->end)
	{
		pthread_mutex_unlock(&(pms->helps[END]));
		return (-1);
	}
	pthread_mutex_unlock(&(pms->helps[END]));
	pthread_mutex_lock(&mutex[n]);
	pms->fork[n] = 1;
	if (print_m(PF, n, pms))
	{
		pthread_mutex_unlock(&mutex[n]);
		return (-1);
	}
	return (0);
}

int	lh_eat(t_pms *pms, t_phl *phl, pthread_mutex_t *mutex, int n)
{
	int	r;

	pthread_mutex_lock(&pms->helps[START]);
	phl->start = get_time(pms->helps);
	pthread_mutex_unlock(&pms->helps[START]);
	r = ft_usleep(pms->etime * 1000, pms);
	pms->fork[n] = 0;
	pthread_mutex_unlock(&mutex[n]);
	pms->fork[(n + 1) % pms->pnb] = 0;
	pthread_mutex_unlock(&mutex[(n + 1) % pms->pnb]);
	if (r)
		return (-1);
	return (0);
}

int	rh_eat(t_pms *pms, t_phl *phl, pthread_mutex_t *mutex, int n)
{
	int	r;

	pthread_mutex_lock(&pms->helps[START]);
	phl->start = get_time(pms->helps);
	pthread_mutex_unlock(&pms->helps[START]);
	r = ft_usleep(pms->etime * 1000, pms);
	pms->fork[(n + 1) % pms->pnb] = 0;
	pthread_mutex_unlock(&mutex[(n + 1) % pms->pnb]);
	pms->fork[n] = 0;
	pthread_mutex_unlock(&mutex[n]);
	if (r)
		return (-1);
	return (0);
}

int	rh_eating(t_pms *pms, t_phl *phl, pthread_mutex_t *mutex, int n)
{
	if (rf(pms, mutex, n))
		return (-1);
	if (lf(pms, mutex, n))
	{
		pms->fork[(n + 1) % pms->pnb] = 0;
		pthread_mutex_unlock(&mutex[(n + 1) % pms->pnb]);
		return (-1);
	}
	if (print_m(PE, n, pms))
	{
		pms->fork[n] = 0;
		pthread_mutex_unlock(&mutex[n]);
		pms->fork[(n + 1) % pms->pnb] = 0;
		pthread_mutex_unlock(&mutex[(n + 1) % pms->pnb]);
		return (-1);
	}	
	if (rh_eat(phl->pms, phl, phl->pms->mutex, phl->id))
		return (-1);
	return (0);
}
