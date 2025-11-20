/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rationalism.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:25:57 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/16 21:17:44 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	atopi(char *s)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (s[i])
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	if (res > 2147483647)
		return (-1);
	return ((int)res);
}

int	not_pi(int ac, char **ags)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (!ags[i][0] || ags[i][0] == '0')
			return (-1);
		while (ags[i][j])
		{
			if (ags[i][j] > '9' || ags[i][j] < '0')
				return (-1);
			j++;
		}
		if (j > 10)
			return (-1);
		if (atopi(ags[i]) <= 0)
			return (-1);
		i++;
	}
	return (0);
}

int	init_mutex(t_pms *pms, t_phl *phl)
{
	int	n;

	n = 0;
	while (n < pms->pnb)
	{
		if (pthread_mutex_init(&((pms->mutex)[n]), NULL) != 0)
		{
			error_management(MM, pms, phl, n);
			return (-1);
		}
		n++;
	}
	n = 0;
	while (n < HELPS)
	{
		if (pthread_mutex_init(&((pms->helps)[n]), NULL) != 0)
		{
			error_management(MH, pms, phl, n);
			return (-1);
		}
		n++;
	}
	return (0);
}

int	do_malloc(t_pms *pms, t_phl **phl)
{
	pms->fork = malloc(sizeof(int) * (pms->pnb));
	pms->mutex = malloc(sizeof(pthread_mutex_t) * (pms->pnb));
	pms->helps = malloc(sizeof(pthread_mutex_t) * HELPS);
	pms->thread = (pthread_t *)malloc(sizeof(pthread_t) * ((pms->pnb)));
	*phl = malloc(sizeof(t_phl) * pms->pnb);
	if (!*phl || !(pms->mutex) || !(pms->helps) || !(pms->fork) || !pms->thread)
	{
		error_management(MALLOC, pms, *phl, 0);
		return (-1);
	}
	memset(pms->fork, 0, pms->pnb * sizeof(int));
	return (0);
}

int	rationalism(int ac, char **ags, t_pms *pms, t_phl **phl)
{
	if ((ac != 5 && ac != 6) || not_pi(ac, ags))
	{
		printf("Wrong parameters.\n");
		return (-1);
	}
	if (atopi(ags[1]) < 1 || (ac == 6 && atopi(ags[5]) == 0))
		return (-1);
	pms->pnb = atopi(ags[1]);
	pms->dtime = atopi(ags[2]);
	pms->etime = atopi(ags[3]);
	pms->stime = atopi(ags[4]);
	pms->mcounts = -1;
	if (ac == 6)
		pms->mcounts = atopi(ags[5]);
	pms->begin = 0;
	pms->tcounts = 0;
	pms->end = 0;
	pms->thread = 0;
	if (do_malloc(pms, phl) == -1)
		return (-1);
	return (0);
}
