/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:25:26 by yzhuang           #+#    #+#             */
/*   Updated: 2022/12/26 21:13:16 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putc(t_stru *stru, char ar)
{
	int	slen;
	int	tlen;

	slen = 1;
	if (stru->wd > slen)
	{
		tlen = stru->wd;
		if (!stru->hyph)
		{
			ft_putnchar(' ', (stru->wd - slen));
			write(1, &ar, 1);
		}
		else
		{
			write(1, &ar, 1);
			ft_putnchar(' ', (stru->wd - slen));
		}
	}
	else
	{
		tlen = slen;
		write(1, &ar, 1);
	}
	return (tlen);
}

int	ft_wd_str(t_stru *stru, int tlen, int slen, char *ar)
{
	if (!stru->hyph)
	{
		ft_putnchar(' ', (stru->wd - slen));
		ft_putnstr(ar, slen);
	}
	else
	{
		ft_putnstr(ar, slen);
		ft_putnchar(' ', (stru->wd - slen));
	}
	tlen = stru->wd;
	return (tlen);
}

int	ft_puts(t_stru *stru, char *ar)
{
	int	slen;
	int	tlen;

	tlen = 0;
	if (ar == NULL)
	{
		if (stru->pt < 6 && stru->pt != -1)
			ar = ft_strdup("");
		else
			ar = ft_strdup("(null)");
	}
	else
		ar = ft_strdup(ar);
	slen = (int) ft_strlen(ar);
	if (stru->pt != -1 && slen > stru->pt)
		slen = stru->pt;
	if (stru->wd > slen)
		tlen = ft_wd_str(stru, tlen, slen, ar);
	else
	{
		tlen = slen;
		ft_putnstr(ar, tlen);
	}
	free(ar);
	return (tlen);
}
