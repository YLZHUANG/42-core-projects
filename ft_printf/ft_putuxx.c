/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:37:57 by yzhuang           #+#    #+#             */
/*   Updated: 2022/12/30 15:21:26 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_zero(t_stru *stru, int pnlen)
{
	if (stru->pt == 0)
		pnlen = 0;
	else if (stru->pt < 0)
		write(1, "0", 1);
	else if (stru->pt >= pnlen)
	{
		ft_putnchar('0', stru->pt);
		pnlen = stru->pt;
	}
	return (pnlen);
}

void	ft_put_uxx(t_stru *stru, int pnlen, unsigned int x)
{
	if (x == 0)
		pnlen = ft_zero(stru, pnlen);
	if (stru->type == 'x' && x != 0)
	{
		if (stru->ht)
			pnlen = ft_write_ht(stru, pnlen);
		if (stru->pt > pnlen)
			ft_putnchar('0', stru->pt - pnlen);
		ft_ubase(x, "0123456789abcdef");
	}
	else if (stru->type == 'X' && x != 0)
	{
		if (stru->ht)
			pnlen = ft_write_ht(stru, pnlen);
		if (stru->pt > pnlen)
			ft_putnchar('0', stru->pt - pnlen);
		ft_ubase(x, "0123456789ABCDEF");
	}
	else if (stru->type == 'u' && x != 0)
	{
		if (stru->pt > pnlen)
			ft_putnchar('0', stru->pt - pnlen);
		ft_ubase(x, "0123456789");
	}
}

void	ft_wd_uxx(t_stru *stru, int tlen, int pnlen, unsigned int u)
{
	if (!stru->hyph)
	{
		if (stru->zero)
			ft_putnchar('0', stru->wd - tlen);
		else
			ft_putnchar(' ', stru->wd - tlen);
		ft_put_uxx(stru, pnlen, u);
	}
	else
	{
		ft_put_uxx(stru, pnlen, u);
		ft_putnchar(' ', stru->wd - tlen);
	}
}

int	ft_putu(t_stru *stru, unsigned int u)
{
	int	pnlen;
	int	tlen;

	if (u == 0 && stru->pt == 0)
		pnlen = 0;
	else
		pnlen = ft_uxxlen(u, 10);
	if (stru->pt > pnlen)
		tlen = stru->pt;
	else
		tlen = pnlen;
	if (stru->wd > tlen)
	{
		ft_wd_uxx(stru, tlen, pnlen, u);
		tlen = stru->wd;
	}
	else
		ft_put_uxx(stru, pnlen, u);
	return (tlen);
}

int	ft_putxx(t_stru *stru, unsigned int x)
{
	int	pnlen;
	int	tlen;

	if (x == 0)
		stru->ht = 0;
	if (x == 0 && stru->pt == 0)
		pnlen = 0;
	else
		pnlen = ft_uxxlen(x, 16);
	if (stru->pt > pnlen)
		tlen = stru->pt + stru->ht;
	else
		tlen = pnlen + stru->ht;
	if (stru->wd > tlen)
	{
		ft_wd_uxx(stru, tlen, pnlen, x);
		tlen = stru->wd;
	}
	else
		ft_put_uxx(stru, pnlen, x);
	return (tlen);
}
