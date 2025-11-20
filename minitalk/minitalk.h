/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:23:04 by yzhuang           #+#    #+#             */
/*   Updated: 2023/08/24 12:36:25 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# define STR_SIZE 32

//**************** Common *****************//

void	ft_putstr(char *s);
int		ft_strcmp(char *s1, char *s2);

//**************** Server *****************//

void	malloc_more(int elen, int len);
void	init_str(int elen);
char	*add_char(char c);
void	s_handler(int sig, siginfo_t *info, void *context);
void	ft_done(int cpid);

//**************** Client *****************//

int		atoi_pid(const char *str);
int		check_pid(char *str);
void	c_handler(int sig);
void	send_c(int pid, char c);

#endif