/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:18:06 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/20 16:00:08 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time(t_rules *r)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		sem_wait(r->sprint);
		printf("Gettimeofday failed\n");
		sem_post(r->sprint);
		exit(-1);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec * 0.001);
}

void	ft_usleep(long u, t_rules *r)
{
	long	b;
	long	t;

	b = get_time(r);
	t = u;
	while (t > USLEEP)
	{
		usleep(USLEEP);
		t = u - ((get_time(r) - b) * 1000);
	}
	if (t > 0)
		usleep(t);
}

long	easy_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("Gettimeofday failed\n");
		exit(-1);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec * 0.001);
}

void	print_m(int o, int i, t_rules *r)
{
	long		t;

	sem_wait(r->sprint);
	t = get_time(r);
	if (o == PD)
		printf("%ld %d died\n", t, i + 1);
	else if (o == PF)
		printf("%ld %d has taken a fork\n", t, i + 1);
	else if (o == PE)
		printf("%ld %d is eating\n", t, i + 1);
	else if (o == PS)
		printf("%ld %d is sleeping\n", t, i + 1);
	else if (o == PT)
		printf("%ld %d is thinking\n", t, i + 1);
	if (o != PD)
		sem_post(r->sprint);
}

void	print_happy(t_rules *rules)
{
	sem_wait(rules->sprint);
	printf("%ld Everyone has eaten enough \U0001F642 \n", get_time(rules));
	sem_post(rules->sprint);
}
