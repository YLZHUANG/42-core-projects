/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:31:07 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/24 13:13:15 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*g_strb = NULL;

void	malloc_more(int elen, int len)
{
	char	*nstr;
	int		i;

	i = 0;
	nstr = malloc(sizeof(char) * elen);
	if (!nstr)
	{
		ft_putstr("Malloc failed.");
		free(g_strb);
		g_strb = NULL;
		exit(1);
	}
	while (i < len)
	{
		nstr[i] = g_strb[i];
		i++;
	}
	nstr[i] = 0;
	if (g_strb)
	{
		free(g_strb);
		g_strb = NULL;
	}
	g_strb = nstr;
}

void	init_str(int elen)
{
	int	i;

	g_strb = malloc(sizeof(char) * elen);
	if (!g_strb)
	{
		write(1, "Malloc failed.", 15);
		exit(0);
	}
	i = -1;
	while (++i < elen)
		g_strb[i] = 0;
}

char	*add_char(char c)
{
	static int	elen = STR_SIZE;
	static int	len = 0;

	if (!g_strb)
		init_str(elen);
	if (len + 1 == elen)
	{
		elen <<= 1;
		malloc_more(elen, len);
	}
	g_strb[len] = c;
	len++;
	if (!c)
	{
		len = 0;
		elen = STR_SIZE;
	}
	return (g_strb);
}

void	ctrl_c(int sig)
{
	if (sig == SIGINT)
	{
		if (g_strb != NULL)
		{
			free(g_strb);
			g_strb = NULL;
		}	
		exit(0);
	}
}

void	s_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned int	c = 0;
	static int			i = 7;
	int					cpid;

	cpid = info->si_pid;
	if (g_strb == NULL)
		init_str(STR_SIZE);
	(void) context;
	c <<= 1;
	c |= (sig == SIGUSR2);
	if (--i == -1)
	{
		g_strb = add_char(c);
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
