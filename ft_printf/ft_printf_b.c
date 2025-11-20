/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:11:13 by yzhuang           #+#    #+#             */
/*   Updated: 2022/12/27 19:55:33 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, int n)
{
	int	i;

	i = 0;
	if (n == 0 || n < 0)
		return ;
	else
	{
		while (i < n)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_putnchar(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}

int	ft_pnlen(int n, int base)
{
	int	pnlen;

	pnlen = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
	{
		pnlen = 1;
		return (pnlen);
	}	
	while (n)
	{
		n = n / base;
		pnlen++;
	}
	return (pnlen);
}

int	ft_uxxlen(long long unsigned n, int base)
{
	int	pnlen;

	pnlen = 0;
	if (n == 0)
	{
		pnlen = 1;
		return (pnlen);
	}	
	while (n)
	{
		n = n / base;
		pnlen++;
	}
	return (pnlen);
}

void	ft_ubase(unsigned long long nbr, char *base)
{
	int					len;
	unsigned long long	nb;

	len = ft_strlen(base);
	if (nbr)
	{
		ft_ubase(nbr / len, base);
		nb = nbr % len;
		write(1, &base[nb], 1);
	}
}
