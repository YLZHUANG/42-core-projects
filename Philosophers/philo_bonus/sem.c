/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:16:46 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/20 17:39:00 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_all(t_rules *rules)
{
	if (sem_close(rules->sforks))
		error_management(SEMC, rules);
	rules->sforks = 0;
	if (sem_close(rules->sstart))
		error_management(SEMC, rules);
	rules->sstart = 0;
	if (sem_close(rules->secount))
		error_management(SEMC, rules);
	rules->secount = 0;
	if (sem_close(rules->sprint))
		error_management(SEMC, rules);
	rules->sprint = 0;
	if (sem_close(rules->scount))
		error_management(SEMC, rules);
	rules->scount = 0;
	if (sem_close(rules->skill))
		error_management(SEMC, rules);
	rules->skill = 0;
	if (sem_close(rules->sdone))
		error_management(SEMC, rules);
	rules->sdone = 0;
}

void	close_unlink(int order, t_rules *rules)
{
	sem_close(rules->sforks);
	rules->sforks = 0;
	sem_unlink("/sforks");
	if (order == SSTART)
		return ;
	sem_close(rules->sstart);
	rules->sstart = 0;
	sem_unlink("/sstart");
	if (order == SECOUNT)
		return ;
	sem_close(rules->secount);
	rules->secount = 0;
	sem_unlink("/secount");
	if (order == SPRINT)
		return ;
	sem_close(rules->sprint);
	rules->sprint = 0;
	sem_unlink("/sprint");
	if (order == SCOUNT)
		return ;
	close_unlink_more(order, rules);
}

void	close_unlink_more(int order, t_rules *rules)
{
	sem_close(rules->scount);
	rules->scount = 0;
	sem_unlink("/scount");
	if (order == SKILL)
		return ;
	sem_close(rules->skill);
	rules->skill = 0;
	sem_unlink("/skill");
	if (order == SDONE)
		return ;
	sem_close(rules->sdone);
	rules->sdone = 0;
	sem_unlink("/sdone");
}

void	unlink_all(void)
{
	sem_unlink("/sforks");
	sem_unlink("/sstart");
	sem_unlink("/secount");
	sem_unlink("/sprint");
	sem_unlink("/sbegin");
	sem_unlink("/scount");
	sem_unlink("/skill");
	sem_unlink("/sdone");
}

void	create_sem(t_rules *rules)
{
	unlink_all();
	rules->sforks = sem_open("/sforks", O_CREAT | O_EXCL, 0777, rules->pnb);
	if (rules->sforks == SEM_FAILED)
		error_management(SFORKS, rules);
	if (rules->pnb == 1)
		return ;
	rules->sstart = sem_open("/sstart", O_CREAT | O_EXCL, 0777, 1);
	if (rules->sstart == SEM_FAILED)
		error_management(SSTART, rules);
	rules->secount = sem_open("/secount", O_CREAT | O_EXCL, 0777, 1);
	if (rules->secount == SEM_FAILED)
		error_management(SECOUNT, rules);
	rules->sprint = sem_open("/sprint", O_CREAT | O_EXCL, 0777, 1);
	if (rules->sprint == SEM_FAILED)
		error_management(SPRINT, rules);
	rules->scount = sem_open("/scount", O_CREAT | O_EXCL, 0777, 0);
	if (rules->scount == SEM_FAILED)
		error_management(SCOUNT, rules);
	rules->skill = sem_open("/skill", O_CREAT | O_EXCL, 0777, 0);
	if (rules->skill == SEM_FAILED)
		error_management(SKILL, rules);
	rules->sdone = sem_open("/sdone", O_CREAT | O_EXCL, 0777, 0);
	if (rules->sdone == SEM_FAILED)
		error_management(SDONE, rules);
}
