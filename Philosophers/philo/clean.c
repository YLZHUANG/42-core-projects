/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:24:27 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/16 14:41:20 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleansing(t_pms *pms, t_phl *phl)
{
	if (pms->mutex)
		free(pms->mutex);
	if (pms->helps)
		free(pms->helps);
	if (pms->thread)
		free(pms->thread);
	if (pms->fork)
		free(pms->fork);
	if (phl)
		free(phl);
	pms->mutex = 0;
	pms->helps = 0;
	pms->thread = 0;
	pms->fork = 0;
	phl = 0;
}

void	destroy_mtx(t_pms *pms, int dn)
{
	int	i;

	i = 0;
	if (!dn)
		return ;
	while (i < dn)
	{
		pthread_mutex_destroy(&pms->mutex[i]);
		i++;
	}
}

void	destroy_hps(t_pms *pms, int dn)
{
	int	i;

	i = 0;
	if (!dn)
		return ;
	while (i < dn)
	{
		pthread_mutex_destroy(&pms->helps[i]);
		i++;
	}
}

void	join_thds(t_pms *pms, t_phl *phl, int dn)
{
	int	i;

	i = 0;
	if (!dn)
		return ;
	while (i < dn)
	{
		pthread_join(pms->thread[i], (void *)&phl[i]);
		i++;
	}
}

void	error_management(int n, t_pms *pms, t_phl *phl, int dn)
{
	if (n == MALLOC)
		printf("System issue: Malloc failed.\n");
	else if (n == MM)
	{
		printf("System issue: pthread_mutex_init failed.\n");
		destroy_mtx(pms, dn);
	}
	else if (n == MH)
	{
		printf("System issue: pthread_mutex_init (helps) failed.\n");
		destroy_mtx(pms, pms->pnb);
		destroy_hps(pms, dn);
	}
	else if (n == PTH)
	{
		printf("System issue: pthread_create failed.\n");
		destroy_mtx(pms, pms->pnb);
		destroy_hps(pms, pms->pnb);
		join_thds(pms, phl, dn);
	}
	cleansing(pms, phl);
}
