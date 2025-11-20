/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:04 by yzhuang           #+#    #+#             */
/*   Updated: 2023/11/20 13:09:50 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>

# define SINGLE 11
# define DEAD -42
# define ENOUGH 42
//**************************** mutex management ****************************//
# define START 0
# define TC 1
# define PRT 2
# define END 3
# define EC 4
# define HELPS 5
//**************************** error management ****************************//
# define MALLOC 21
# define PTH 22
# define MM 25
# define MH 26
# define ML 27
# define MU 28
# define ERROR -1
//**************************** print management ****************************//
# define PF 9
# define PE 8
# define PS 7
# define PT 6
# define PD 19
# define PH 18
# define USLEEP 4000

typedef struct s_pms
{
	int				pnb;
	int				dtime;
	int				etime;
	int				stime;
	int				mcounts;
	long			begin;
	int				tcounts;
	int				end;
	pthread_t		*thread;
	int				*fork;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*helps;
}	t_pms;

typedef struct s_phl
{
	int				id;
	long			start;
	int				ecount;
	t_pms			*pms;
}	t_phl;

//**************************** rationalism ********************************//
int		atopi(char *s);
int		not_pi(int ac, char **ags);
int		init_mutex(t_pms *pms, t_phl *phl);
int		do_malloc(t_pms *pms, t_phl **phl);
int		rationalism(int ac, char **ags, t_pms *pms, t_phl **phl);

//**************************** genesis ************************************//
void	*philo(void *arg);
int		genesis(t_pms *pms, t_phl *phl);

//**************************** questionning ********************************//
int		questionning(t_pms *pms, t_phl *phl);
int		find_starved(t_pms *pms, t_phl *phl, int pnb);
void	happy_ending(t_pms *p);
void	not_to_be(t_pms *pms, t_phl *phl);

//**************************** eat management ******************************//
int		rf(t_pms *pms, pthread_mutex_t *mutex, int n);
int		lf(t_pms *pms, pthread_mutex_t *mutex, int n);
int		rh_eat(t_pms *pms, t_phl *phl, pthread_mutex_t *mutex, int n);
int		lh_eat(t_pms *pms, t_phl *phl, pthread_mutex_t *mutex, int n);
int		rh_eating(t_pms *pms, t_phl *phl, pthread_mutex_t *mutex, int n);
int		lh_eating(t_pms *pms, t_phl *phl, pthread_mutex_t *mutex, int n);

//**************************** life management ****************************//
int		eating(t_phl *phl);
int		sleeping(t_phl *phl, t_pms *pms);
int		thinking(t_phl *phl, t_pms *pms);
void	living(t_phl *phl, t_pms *pms);

//*********************** single life management ****************************//
void	single_question(t_pms *pms, pthread_mutex_t *mutex, int id);
void	single_life(int thread, t_pms *pms, pthread_mutex_t *mutex, int id);

//**************************** support functions ****************************//
long	get_time(pthread_mutex_t *helps);
int		ft_usleep(long u, t_pms *pms);
int		print_m(int o, int i, t_pms *p);
void	destroy_mtx(t_pms *pms, int dn);
void	destroy_hps(t_pms *pms, int dn);
void	join_thds(t_pms *pms, t_phl *phl, int dn);
void	cleansing(t_pms *pms, t_phl *phl);
void	error_management(int n, t_pms *pms, t_phl *phl, int dn);

#endif