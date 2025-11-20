/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:14 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/16 14:44:09 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	single_question(t_pms *pms, pthread_mutex_t *mutex, int id)
{
	pms->begin = get_time(pms->helps);
	if (!pms->begin)
		return ;
	pthread_mutex_lock(&mutex[0]);
	pms->fork[0] = 1;
	printf("%ld %d has taken a fork\n",
		get_time(pms->helps) - pms->begin, id + 1);
	usleep(pms->dtime * 1000 - 10);
	pthread_mutex_unlock(&mutex[0]);
	pthread_mutex_lock(&(pms->helps[END]));
	pms->end = -1;
	pthread_mutex_unlock(&(pms->helps[END]));
	printf("%ld %d died\n", get_time(pms->helps) - pms->begin, 1);
}

void	single_life(int thread, t_pms *pms, pthread_mutex_t *mutex, int id)
{
	if (thread == 0)
	{
		usleep(pms->dtime * 1000 - 10);
		pthread_mutex_lock(&(pms->helps[END]));
		while (!pms->end)
		{
			pthread_mutex_unlock(&(pms->helps[END]));
			usleep(30);
			pthread_mutex_lock(&(pms->helps[END]));
		}
		pthread_mutex_unlock(&(pms->helps[END]));
	}
	else if (thread == 1)
		single_question(pms, mutex, id);
}
