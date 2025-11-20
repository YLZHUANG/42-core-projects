/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:48:56 by yzhuang           #+#    #+#             */
/*   Updated: 2023/01/03 13:36:09 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	istype(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

int	ft_gettype(const char *f, int i)
{
	i++;
	while (f[i])
	{
		if (istype(f[i]))
			return (i);
		i++;
	}	
	return (0);
}

int	ft_write_ht(t_stru *stru, int pnlen)
{
	if (stru->type == 'X')
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
	pnlen += 2;
	return (pnlen);
}
