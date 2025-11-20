/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:50:31 by yzhuang           #+#    #+#             */
/*   Updated: 2022/12/30 13:57:14 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsef(const char *f, int i, va_list *ap, int tlen)
{
	while (f[i])
	{
		if (f[i] == '%')
		{
			if (ft_gettype(f, i))
			{	
				tlen = ft_struct(f, i, ap, tlen);
				i = ft_gettype(f, i);
			}
			else
				return (0);
		}
		else
		{
			write(1, &f[i], 1);
			tlen++;
		}
		i++;
	}
	return (tlen);
}

int	ft_printf(const char *f, ...)
{
	va_list	ap;
	int		i;
	int		tlen;

	tlen = 0;
	i = 0;
	va_start(ap, f);
	tlen = ft_parsef(f, i, &ap, tlen);
	va_end(ap);
	return (tlen);
}
