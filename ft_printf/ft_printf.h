/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:02:27 by yzhuang           #+#    #+#             */
/*   Updated: 2023/01/03 13:37:03 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_stru
{
	va_list	*ap;
	int		wd;
	int		pt;
	int		hyph;
	int		zero;
	int		ht;
	int		sp;
	int		ps;
	int		type;
}	t_stru;

/*---basic support fonctions---*/
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strdup(const char *s1);
void	ft_putnstr(char *str, int n);
void	ft_putnchar(char c, int n);
int		istype(char c);
int		ft_write_ht(t_stru *stru, int pnlen);
int		ft_gettype(const char *f, int i);
void	ft_ubase(unsigned long long nbr, char *base);
/*---fonctions for different types---*/
int		ft_zero(t_stru *stru, int pnlen);
int		ft_pnlen(int n, int base);
int		ft_uxxlen(long long unsigned n, int base);
int		ft_putc(t_stru *stru, char ar);
int		ft_wd_str(t_stru *stru, int tlen, int slen, char *ar);
int		ft_puts(t_stru *stru, char *ar);
void	ft_put_ptr(long long unsigned p);
int		ft_putptr(t_stru *stru, long long unsigned p);
void	ft_put_n(t_stru *stru, int tlen, int pnlen, int d);
void	ft_wd_n(t_stru *stru, int tlen, int pnlen, int d);
int		ft_putn(t_stru *stru, int d);
void	ft_put_uxx(t_stru *stru, int pnlen, unsigned int x);
void	ft_wd_uxx(t_stru *stru, int tlen, int pnlen, unsigned int u);
int		ft_putxx(t_stru *stru, unsigned int x);
int		ft_putu(t_stru *stru, unsigned int u);
/*-------------core fonctions-------------*/
t_stru	*stru_init(t_stru *stru, va_list *ap);
int		stru_fill_digit(const char *f, int i, t_stru *stru);
void	stru_fill(const char *f, int i, t_stru *stru);
int		stru_write(t_stru *stru);
int		ft_struct(const char *f, int i, va_list *ap, int tlen);
int		ft_parsef(const char *f, int i, va_list *ap, int tlen);
int		ft_printf(const char *f, ...);

#endif
