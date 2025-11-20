/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:11:58 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/20 17:08:39 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>

# define AGS 0
# define SEM 1
# define SEMC 2
# define FORK 3
# define PTH 4
# define PTHP 5
# define PTHJ 15
# define ERROR -1
# define DEAD -42
# define HAPPY 42
# define SFORKS 20
# define SSTART 21
# define SECOUNT 22
# define SPRINT 23
# define SCOUNT 19
# define SKILL 24
# define SDONE 25
# define ALL 26
# define PF 9
# define PE 8
# define PS 7
# define PT 6
# define PD 19
# define PH 18
# define USLEEP 4000

typedef struct s_rules
{
	int		pnb;
	int		dtime;
	int		etime;
	int		stime;
	int		mcounts;
	int		pid[500];
	sem_t	*sforks;
	sem_t	*sstart;
	sem_t	*secount;
	sem_t	*sprint;
	sem_t	*scount;
	sem_t	*skill;
	sem_t	*sdone;
}	t_rules;

typedef struct s_phl
{
	long	start;
	int		id;
	int		ecount;
	t_rules	*rules;
}	t_phl;

//**************************** support functions **************************//

int		atopi(char *s);
int		not_pi(int ac, char **ags);
void	kill_error(t_rules *r);
void	error_management(int n, t_rules *rules);

//**************************** semaphore management ************************//

void	close_all(t_rules *rules);
void	close_unlink(int order, t_rules *rules);
void	close_unlink_more(int order, t_rules *rules);
void	unlink_all(void);
void	create_sem(t_rules *rules);

//****************************time and  print management *******************//

long	easy_get_time(void);
long	get_time(t_rules *r);
void	ft_usleep(long u, t_rules *r);
void	print_m(int o, int i, t_rules *r);
void	print_happy(t_rules *rules);

//**************************** actions management **************************//

void	eating(int id, t_phl *phl, t_rules *rules);
void	sleeping(int id, t_rules *rules);
void	thinking(int id, t_rules *rules);
void	single_life(t_rules *rules);

//**************************** life management ******************************//

int		is_enough(t_rules *rules, t_phl *phl);
int		is_dead(t_rules *rules, t_phl *phl);
void	*questionning(void *arg);
void	living(int id, t_phl *phl, t_rules *rules);
void	philo(int id, t_phl *phl, t_rules *rules);

//**************************** core functions *******************************//

void	*enough(void *arg);
void	*kill_all(void *arg);
void	expansion(t_rules *rules, t_phl *phl);
int		bigbang(t_rules *rules, t_phl *phl);
int		preconceptual(int ac, char **ags, t_rules *rules);

#endif