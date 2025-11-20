/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:45:23 by yzhuang           #+#    #+#             */
/*   Updated: 2023/02/21 15:45:26 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	is_line(char *s)
{
	size_t	n;

	n = 0;
	if (!s)
		return (0);
	while (s[n])
	{
		if (s[n] == '\n')
			return (n + 1);
		n++;
	}		
	return (0);
}

void	ft_laddback(t_buf **lst, t_buf *new)
{
	t_buf	*t;

	t = NULL;
	t = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (t->next)
			t = t->next;
		t->next = new;
	}
}

size_t	ft_lstlen(t_buf **lst)
{
	size_t	len;
	t_buf	*t;

	t = NULL;
	len = 0;
	t = *lst;
	if (lst)
	{
		while (*lst)
		{
			len += (*lst)->len;
			*lst = (*lst)->next;
		}
	}
	*lst = t;
	return (len);
}

void	ft_free_lst(t_buf **lst)
{
	t_buf	*t;

	t = NULL;
	if (lst)
	{
		while (*lst)
		{
			t = (*lst)->next;
			free((*lst)->str);
			free(*lst);
			*lst = t;
		}
	}
	*lst = NULL;
}

void	update_buf(int i, char *buf)
{
	int	j;

	j = 0;
	if (j < (BUFFER_SIZE - i))
	{
		while (j < (BUFFER_SIZE - i) && buf[i + j])
		{
			buf[j] = buf[i + j];
			j++;
		}
	}	
	while (buf[j])
	{
		buf[j] = '\0';
		j++;
	}	
}
