/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:45:39 by yzhuang           #+#    #+#             */
/*   Updated: 2022/12/27 20:27:20 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr(long long unsigned p)
{
	if (p == 0)
	{
		ft_putstr_fd("(nil)", 1);
	}
	else
	{
		write(1, "0x", 2);
		ft_ubase(p, "0123456789abcdef");
	}
}

int	ft_putptr(t_stru *stru, long long unsigned p)
{
	int	tlen;

	if (p == 0)
		tlen = 5;
	else
	tlen = ft_uxxlen(p, 16) + 2;
	if (stru->wd > tlen)
	{
		if (!stru->hyph)
		{
			ft_putnchar(' ', stru->wd - tlen);
			ft_put_ptr(p);
		}
		else
		{
			ft_put_ptr(p);
			ft_putnchar(' ', stru->wd - tlen);
		}
		tlen = stru->wd;
	}
	else
		ft_put_ptr(p);
	return (tlen);
}
