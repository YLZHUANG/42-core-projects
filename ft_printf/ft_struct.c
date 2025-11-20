/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:47:57 by yzhuang           #+#    #+#             */
/*   Updated: 2022/12/30 14:18:44 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stru	*stru_init(t_stru *stru, va_list *ap)
{
	stru->wd = 0;
	stru->pt = -1;
	stru->hyph = 0;
	stru->zero = 0;
	stru->ht = 0;
	stru->sp = 0;
	stru->ps = 0;
	stru->type = 0;
	stru->ap = ap;
	return (stru);
}

int	stru_fill_digit(const char *f, int i, t_stru *stru)
{
	if (f[i] == '0' && !ft_isdigit(f[i - 1]))
		stru->zero = 1;
	else if (ft_isdigit(f[i]) && (f[i] != '0'))
	{
		stru->wd = ft_atoi(&f[i]);
		i += (ft_pnlen(stru->wd, 10) - 1);
	}
	else if (f[i] == '.')
	{
		if (ft_isdigit(f[i + 1]))
		{
			stru->pt = ft_atoi(&f[i + 1]);
			i += ft_pnlen(stru->pt, 10);
		}	
		else
			stru->pt = 0;
	}
	return (i);
}

void	stru_fill(const char *f, int i, t_stru *stru)
{
	i++;
	while (f[i] && !istype(f[i]))
	{
		if (f[i] == '-')
			stru->hyph = 1;
		else if (f[i] == '#')
			stru->ht = 2;
		else if (f[i] == ' ')
			stru->sp = 1;
		else if (f[i] == '+')
			stru->ps = 1;
		else if (f[i] == '.' || ft_isdigit(f[i]))
			i = stru_fill_digit(f, i, stru);
		i++;
	}
	if (stru->ps)
		stru->sp = 0;
	if (stru->pt >= 0 || stru->hyph)
		stru->zero = 0;
	if (istype(f[i]))
		stru->type = f[i];
}

int	stru_write(t_stru *stru)
{
	int	tlen;

	tlen = 0;
	if (stru->type == 'c')
		tlen = ft_putc(stru, va_arg(*(stru->ap), int));
	else if (stru->type == 's')
		tlen = ft_puts(stru, va_arg(*(stru->ap), char *));
	else if (stru->type == 'p')
		tlen = ft_putptr(stru, va_arg(*(stru->ap), long long unsigned));
	else if (stru->type == 'd' || stru->type == 'i')
		tlen = ft_putn(stru, va_arg(*(stru->ap), int));
	else if (stru->type == 'u')
		tlen = ft_putu(stru, va_arg(*(stru->ap), unsigned int));
	else if (stru->type == 'X' || stru->type == 'x')
		tlen = ft_putxx(stru, va_arg(*(stru->ap), unsigned int));
	else if (stru->type == '%')
		tlen = write(1, "%", 1);
	return (tlen);
}

int	ft_struct(const char *f, int i, va_list *ap, int tlen)
{
	t_stru	*stru;

	stru = malloc(sizeof(t_stru));
	if (!stru)
		return (0);
	stru_init(stru, ap);
	stru_fill(f, i, stru);
	tlen += stru_write(stru);
	free(stru);
	return (tlen);
}
