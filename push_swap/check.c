/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:46:55 by yzhuang           #+#    #+#             */
/*   Updated: 2023/06/27 16:38:08 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dup(int *tab, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < (ac -1))
	{
		j = 1;
		while (j < ac - 1 - i)
		{
			if (tab[i] == tab[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	stoi(const char *str, int *tab)
{
	int		s;
	long	res;

	s = 1;
	res = 0;
	if (*str && *str == '-')
	{
		s *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (s < 0)
		res = -res;
	if (res < -2147483648 || res > 2147483647)
		ft_exit(tab);
	return (res);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	lst_is_sorted(t_lst *lst)
{
	if (!lst)
		return (-1);
	while (lst && lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	check_ags(int ac, char **ags, int *tab)
{
	int	i;

	ac--;
	while (ac > 0)
	{
		i = 0;
		if (ags[ac][0] != '-' && (!(ft_isdigit(ags[ac][0]))))
			ft_exit(tab);
		if (ags[ac][0] == '-')
		{
			if (!ags[ac][1])
				ft_exit(tab);
			i++;
		}	
		while (ags[ac][i])
		{
			if (!(ft_isdigit(ags[ac][i])))
				ft_exit(tab);
			i++;
		}
		ac--;
	}
}
