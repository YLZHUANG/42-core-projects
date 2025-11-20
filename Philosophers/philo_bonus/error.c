/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:32 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/20 16:10:49 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	error_pth(int n, t_rules *rules)
{
	if (n == PTH)
	{
		printf("Pthread_create (child) failed.\n");
		close_all(rules);
	}	
	else if (n == PTHP)
	{
		printf("Pthread create (parent) failed.\n");
		kill_error(rules);
		close_unlink(ALL, rules);
	}
	else if (n == PTHJ)
	{
		printf("Pthread join failed.\n");
		close_unlink(ALL, rules);
	}
}

static void	error_sem(int n, t_rules *rules)
{
	if (n == SFORKS)
		printf("Semaphore open sforks failed.\n");
	if (n == SSTART)
	{
		printf("Semaphore open sstart failed.\n");
		close_unlink(SSTART, rules);
	}
	else if (n == SECOUNT)
	{
		printf("Semaphore open secount failed.\n");
		close_unlink(SECOUNT, rules);
	}	
	else if (n == SCOUNT)
	{
		printf("Semaphore open sebegin failed.\n");
		close_unlink(SCOUNT, rules);
	}
}

static void	error_sem_more(int n, t_rules *rules)
{
	if (n == SKILL)
	{
		printf("Semaphore open skill failed.\n");
		close_unlink(SKILL, rules);
	}
	else if (n == SPRINT)
	{
		printf("Semaphore open sprint failed.\n");
		close_unlink(SPRINT, rules);
	}
	else if (n == SDONE)
	{
		printf("Semaphore open sdone failed.\n");
		close_unlink(SDONE, rules);
	}
	else if (n == SEMC)
		printf("Sem_close failed.\n");
}

void	error_management(int n, t_rules *rules)
{
	if (n == AGS)
		printf("Wrong parameters.\n");
	else if (n == FORK)
	{
		printf("Fork() failed.\n");
		kill_error(rules);
		close_unlink(ALL, rules);
	}
	else if (n == PTH || n == PTHP || n == PTHJ)
		error_pth(n, rules);
	else if (n == SFORKS || n == SSTART || n == SECOUNT || n == SCOUNT)
		error_sem(n, rules);
	else if (n == SKILL || n == SPRINT || n == SDONE || n == SEMC)
		error_sem_more(n, rules);
	exit(-1);
}
