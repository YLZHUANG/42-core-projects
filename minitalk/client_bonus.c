/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:19:11 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/24 13:15:19 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_bsleep = 1;

int	atoi_pid(const char *str)
{
	int	res;

	res = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 9)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	c_handler(int sig)
{
	g_bsleep = 0;
	if (sig == SIGUSR2)
	{
		ft_putstr("Message received! \U0001f984");
		exit(0);
	}
}

void	send_c(int pid, char c)
{
	int	bi;

	bi = 7;
	while (bi >= 0)
	{
		if (c & (1 << bi))
		{
			if (kill(pid, SIGUSR2))
				(ft_putstr("No connection. \U0001F610"), exit(1));
		}
		else
		{
			if (kill(pid, SIGUSR1))
				(ft_putstr("No connection. \U0001F610"), exit(1));
		}
		bi--;
		while (g_bsleep)
			usleep(80);
		g_bsleep = 1;
	}
}

int	main(int ac, char **ags)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr("Incorrect number of arguments. \U0001F605 Two expected.");
		return (-1);
	}
	if (!check_pid(ags[1]))
	{
		ft_putstr("Incorrect PID. \U0001F605");
		return (-1);
	}
	signal(SIGUSR1, c_handler);
	signal(SIGUSR2, c_handler);
	pid = atoi_pid(ags[1]);
	while (ags[2][i])
	{
		send_c(pid, ags[2][i]);
		i++;
	}
	send_c(pid, 0);
	return (0);
}
