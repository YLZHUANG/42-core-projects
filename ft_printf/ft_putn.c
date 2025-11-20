/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:25:48 by yzhuang           #+#    #+#             */
/*   Updated: 2022/12/30 15:57:38 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_n(t_stru *stru, int tlen, int pnlen, int d)
{
	if (stru->sp && (d >= 0 || stru->pt == 0))
		write(1, " ", 1);
	if (stru->ps && d >= 0)
		write(1, "+", 1);
	else if (d < 0 && d != -2147483648)
	{
		write(1, "-", 1);
		d *= -1;
	}
	else if (d == -2147483648)
		write(1, "-", 1);
	if (d == 0 && stru->pt == 0)
		return ;
	if (stru->pt > pnlen)
		ft_putnchar('0', stru->pt - pnlen);
	if (stru->wd > tlen && stru->zero)
		ft_putnchar('0', stru->wd - tlen);
	if (d == -2147483648)
		write(1, "2147483648", 10);
	else
		ft_putnbr_fd(d, 1);
}

void	ft_wd_n(t_stru *stru, int tlen, int pnlen, int d)
{
	if (stru->zero)
		ft_put_n(stru, tlen, pnlen, d);
	else
	{
		if (!stru->hyph)
		{
			ft_putnchar(' ', stru->wd - tlen);
			ft_put_n(stru, tlen, pnlen, d);
		}
		else
		{
			ft_put_n(stru, tlen, pnlen, d);
			ft_putnchar(' ', stru->wd - tlen);
		}
	}
}

int	ft_putn(t_stru *stru, int d)
{
	int	pnlen;
	int	tlen;

	if (d < 0)
		stru->ps = 1;
	if (!(d >= 0 || stru->pt == 0))
		stru->sp = 0;
	if (d == 0 && stru->pt == 0)
		pnlen = 0;
	else
		pnlen = ft_pnlen(d, 10);
	if (stru->pt > pnlen)
		tlen = stru->pt + stru->ps + stru->sp;
	else
		tlen = pnlen + stru->ps + stru->sp;
	if (stru->wd > tlen)
	{
		ft_wd_n(stru, tlen, pnlen, d);
		tlen = stru->wd;
	}
	else
		ft_put_n(stru, tlen, pnlen, d);
	return (tlen);
}
