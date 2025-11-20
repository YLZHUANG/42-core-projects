/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:18:42 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/20 15:54:08 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	kill_error(t_rules *r)
{
	int	n;

	n = 0;
	while (n < r->pnb)
	{
		kill(r->pid[n], SIGKILL);
		n++;
	}
}
