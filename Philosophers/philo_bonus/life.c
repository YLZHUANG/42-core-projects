/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:10:08 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/20 18:33:38 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_enough(t_rules *rules, t_phl *phl)
{
	sem_wait(rules->secount);
	if (phl->ecount == rules->mcounts)
	{
		sem_post(rules->secount);
		return (1);
	}
	sem_post(rules->secount);
	return (0);
}

int	is_dead(t_rules *rules, t_phl *phl)
{
	return (get_time(rules) - phl->start >= rules->dtime);
}

void	*questionning(void *arg)
{
	t_phl		*phl;
	t_rules		*r;

	phl = (t_phl *)arg;
	r = phl->rules;
	while (1)
	{
		usleep(800);
		sem_wait(r->sstart);
		if (get_time(r) - phl->start >= r->dtime)
		{
			print_m(PD, phl->id, phl->rules);
			sem_post(r->skill);
			return (NULL);
		}
		sem_post(r->sstart);
		if (is_enough(r, phl))
			return (NULL);
	}
	return (NULL);
}

void	living(int id, t_phl *phl, t_rules *rules)
{
	pthread_t	q;

	if (pthread_create(&q, NULL, &questionning, phl) != 0)
		error_management(PTH, rules);
	if (!(phl->id % 2))
		ft_usleep(rules->etime * 1000, rules);
	while (1)
	{
		eating(id, phl, rules);
		sem_wait(rules->secount);
		phl->ecount++;
		if (phl->ecount == rules->mcounts)
		{
			sem_post(rules->secount);
			if (pthread_join(q, NULL))
				error_management(PTHJ, rules);
			close_all(rules);
			exit(HAPPY);
		}
		sem_post(rules->secount);
		sleeping(id, rules);
		thinking(id, rules);
	}
}

void	philo(int id, t_phl *phl, t_rules *rules)
{
	sem_wait(rules->secount);
	phl->ecount = 0;
	sem_post(rules->secount);
	living(id, phl, rules);
}
