/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:31:07 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/24 13:25:35 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str = NULL;

void	ft_done(int cpid)
{
	int	s;

	s = 0;
	if (!(ft_strcmp(g_str, "exit")))
		s = 1;
	ft_putstr(g_str);
	if (g_str)
		free(g_str);
	g_str = NULL;
	kill(cpid, SIGUSR2);
	if (s)
		exit(0);
}

void	malloc_more(int elen, int len)
{
	char	*nstr;
	int		i;

	i = 0;
	nstr = malloc(sizeof(char) * elen);
	if (!nstr)
	{
		ft_putstr("Malloc failed.");
		free(g_str);
		g_str = NULL;
		exit(1);
	}
	while (i < len)
	{
		nstr[i] = g_str[i];
		i++;
	}
	nstr[i] = 0;
	if (g_str)
	{
		free(g_str);
		g_str = NULL;
	}
	g_str = nstr;
}

void	init_str(int elen)
{
	int	i;

	g_str = malloc(sizeof(char) * elen);
	if (!g_str)
	{
		write(1, "Malloc failed.", 15);
		exit(0);
	}
	i = -1;
	while (++i < elen)
		g_str[i] = 0;
}

char	*add_char(char c)
{
	static int	elen = STR_SIZE;
	static int	len = 0;

	if (!g_str)
		init_str(elen);
	if (len + 1 == elen)
	{
		elen <<= 1;
		malloc_more(elen, len);
	}
	g_str[len] = c;
	len++;
	if (!c)
	{
		len = 0;
		elen = STR_SIZE;
	}
	return (g_str);
}

void	s_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned int	c = 0;
	static int			i = 7;
	int					cpid;

	cpid = info->si_pid;
	if (g_str == NULL)
		init_str(STR_SIZE);
	(void) context;
	c <<= 1;
	c |= (sig == SIGUSR2);
	if (--i == -1)
	{
		g_str = add_char(c);
		if (c == 0)
		{
			ft_done(cpid);
			c = 0;
			i = 7;
			return ;
		}
		c = 0;
		i = 7;
	}
	kill(cpid, SIGUSR1);
}
