/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:24:34 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/20 15:59:21 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*enough(void *arg)
{
	int	n;
	int	being;
	int	stat_loc;
	int	c;

	n = 0;
	c = 0;
	being = 1;
	while (n < ((t_rules *)arg)->pnb)
	{
		waitpid(-1, &stat_loc, 0);
		if (WIFEXITED(stat_loc))
			being = WEXITSTATUS(stat_loc);
		if (being == ERROR)
			break ;
		if (being == HAPPY)
			c++;
		n++;
	}
	if (c == ((t_rules *)arg)->pnb)
		print_happy(((t_rules *)arg));
	sem_post(((t_rules *)arg)->skill);
	return (NULL);
}

void	*kill_all(void *arg)
{
	int		n;
	t_rules	*r;

	n = 0;
	r = (t_rules *)arg;
	sem_wait(r->skill);
	while (n < r->pnb)
	{
		kill(r->pid[n], SIGKILL);
		sem_post(r->scount);
		n++;
	}
	sem_post(r->sdone);
	return (NULL);
}

int	main(int ac, char **ags)
{
	t_rules		rules;
	t_phl		phl;
	pthread_t	kill;
	pthread_t	count;

	if (preconceptual(ac, ags, &rules) == -1)
		return (-1);
	if (bigbang(&rules, &phl) == DEAD)
		return (0);
	expansion(&rules, &phl);
	if (pthread_create(&count, NULL, &enough, &rules) != 0)
		error_management(PTHP, &rules);
	if (pthread_create(&kill, NULL, &kill_all, &rules) != 0)
		error_management(PTHP, &rules);
	if (pthread_join(count, NULL))
		error_management(PTHJ, &rules);
	if (pthread_join(kill, NULL))
		error_management(PTHJ, &rules);
	sem_wait(rules.sdone);
	close_unlink(ALL, &rules);
	return (0);
}
