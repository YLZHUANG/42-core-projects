/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:22:34 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/16 14:41:58 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(pthread_mutex_t *helps)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		pthread_mutex_lock(&(helps[PRT]));
		printf("Gettimeofday failed\n");
		pthread_mutex_unlock(&(helps[PRT]));
		return (0);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_usleep(long u, t_pms *pms)
{
	long	b;
	long	t;

	b = get_time(pms->helps);
	t = u;
	while (t > USLEEP)
	{
		usleep(USLEEP);
		pthread_mutex_lock(&(pms->helps[END]));
		if (pms->end)
		{
			pthread_mutex_unlock(&(pms->helps[END]));
			return (-1);
		}
		pthread_mutex_unlock(&(pms->helps[END]));
		t = u - ((get_time(pms->helps) - b) * 1000);
	}
	if (t > 0)
		usleep(t);
	return (0);
}

int	print_m(int o, int i, t_pms *p)
{
	static int	f = 0;
	long		t;

	pthread_mutex_lock(&(p->helps[PRT]));
	if (f == 1)
	{
		pthread_mutex_unlock(&(p->helps[PRT]));
		return (DEAD);
	}
	t = get_time(p->helps);
	if (o == PD)
	{
		f = 1;
		printf("%ld %d died\n", t - p->begin, i + 1);
	}
	else if (o == PF)
		printf("%ld %d has taken a fork\n", t - p->begin, i + 1);
	else if (o == PE)
		printf("%ld %d is eating\n", t - p->begin, i + 1);
	else if (o == PS)
		printf("%ld %d is sleeping\n", t - p->begin, i + 1);
	else if (o == PT)
		printf("%ld %d is thinking\n", t - p->begin, i + 1);
	pthread_mutex_unlock(&(p->helps[PRT]));
	return (0);
}
