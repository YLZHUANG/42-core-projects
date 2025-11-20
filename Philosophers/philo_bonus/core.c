/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:20:43 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/20 17:39:11 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	expansion(t_rules *rules, t_phl *phl)
{
	int	n;

	n = 0;
	while (n < rules->pnb)
	{
		phl->id = n;
		rules->pid[n] = fork();
		if (rules->pid[n] < 0)
			error_management(FORK, rules);
		if (rules->pid[n] == 0)
		{
			phl->start = get_time(rules);
			philo(n, phl, rules);
		}
		usleep(100);
		n++;
	}
}

int	bigbang(t_rules *rules, t_phl *phl)
{
	if (rules->pnb == 1)
	{
		single_life(rules);
		return (DEAD);
	}
	phl->id = 0;
	phl->ecount = 0;
	phl->start = 0;
	phl->rules = rules;
	return (0);
}

int	preconceptual(int ac, char **ags, t_rules *rules)
{
	if ((ac != 5 && ac != 6) || not_pi(ac, ags))
		error_management(AGS, 0);
	if (atopi(ags[1]) == 0 || (ac == 6 && atopi(ags[5]) == 0))
		exit (0);
	rules->pnb = atopi(ags[1]);
	if (rules->pnb > 500)
		error_management(AGS, 0);
	rules->dtime = atopi(ags[2]);
	rules->etime = atopi(ags[3]);
	rules->stime = atopi(ags[4]);
	rules->mcounts = -1;
	if (ac == 6)
		rules->mcounts = atopi(ags[5]);
	memset(rules->pid, 0, 500 * sizeof(int));
	create_sem(rules);
	return (0);
}
