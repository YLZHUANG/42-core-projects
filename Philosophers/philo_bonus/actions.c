/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:09:42 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/20 17:28:07 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(int id, t_phl *phl, t_rules *rules)
{
	sem_wait(rules->sforks);
	print_m(PF, id, rules);
	sem_wait(rules->sforks);
	print_m(PF, id, rules);
	sem_wait(rules->sstart);
	phl->start = get_time(rules);
	sem_post(rules->sstart);
	print_m(PE, id, rules);
	ft_usleep(rules->etime * 1000, rules);
	sem_post(rules->sforks);
	sem_post(rules->sforks);
}

void	sleeping(int id, t_rules *rules)
{
	print_m(PS, id, rules);
	ft_usleep(rules->stime * 1000, rules);
}

void	thinking(int id, t_rules *rules)
{
	print_m(PT, id, rules);
	usleep(200);
}

void	single_life(t_rules *rules)
{
	sem_wait(rules->sforks);
	printf("%ld %d has taken a fork\n", easy_get_time(), 1);
	usleep(rules->dtime * 1000);
	sem_post(rules->sforks);
	printf("%ld %d died\n", easy_get_time(), 1);
	sem_close(rules->sforks);
	rules->sforks = 0;
	sem_unlink("/sforks");
}
