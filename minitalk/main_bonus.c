/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:40:24 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/24 14:20:42 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

extern char	*g_strb;

void	ft_done(int cpid)
{
	int	s;

	s = 0;
	if (!(ft_strcmp(g_strb, "exit")))
		s = 1;
	else
		ft_putstr(g_strb);
	if (g_strb)
		free(g_strb);
	g_strb = NULL;
	kill(cpid, SIGUSR2);
	if (s)
	{
		ft_putstr("exit \n\U0001F48B");
		exit(0);
	}
}

int	main(void)
{
	struct sigaction	act;
	sigset_t			mask;

	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	act.sa_mask = mask;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = s_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	signal(SIGINT, ctrl_c);
	ft_printf("Hello! 你好! \U0001F642 The server PID is : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
