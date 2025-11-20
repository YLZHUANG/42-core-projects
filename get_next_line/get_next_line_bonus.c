/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:42:18 by yzhuang           #+#    #+#             */
/*   Updated: 2023/02/21 16:08:22 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*save_buf(char *buf, int n_read, char *str, size_t n)
{
	int	i;

	i = 0;
	if (n)
		n_read = n;
	str = malloc(sizeof(char *) * (n_read + 1));
	if (!str)
		return (NULL);
	while (((n && buf[i] && buf[i] != '\n')) || (!n && i < n_read))
	{
		str[i] = buf[i];
		i++;
	}	
	if (buf[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	if (i <= BUFFER_SIZE)
		update_buf(i, buf);
	return (str);
}

void	build_new(t_buf **save, char *buf, int n_read, size_t n)
{
	t_buf	*new;

	new = malloc(sizeof(t_buf));
	if (!new)
		return ;
	if (!n && n_read == 0)
	{
		while (buf[n_read])
			n_read++;
	}
	new->str = save_buf(buf, n_read, new->str, n);
	if (n)
		new->len = n;
	else
		new->len = n_read;
	new->next = NULL;
	ft_laddback(save, new);
}

void	build_save(int fd, t_buf **save, char *buf, int n_read)
{	
	size_t	n;

	n = is_line(buf);
	build_new(save, buf, n_read, n);
	if (n || (n_read > 0 && n_read < BUFFER_SIZE))
		return ;
	n_read = 1;
	while (n_read > 0)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read < 0)
			return ;
		else if (n_read > 0)
		{
			n = is_line(buf);
			build_new(save, buf, n_read, n);
			if (n || n_read < BUFFER_SIZE)
				break ;
		}
		else if (n_read == 0)
			break ;
	}
}

char	*get_line(int fd, char *buf, t_buf **save, int n_read)
{
	size_t	i;
	size_t	j;
	char	*line;
	t_buf	*tmp;

	i = 0;
	j = 0;
	build_save(fd, save, buf, n_read);
	line = malloc(sizeof(char) * (ft_lstlen(save) + 1));
	if (!line)
		return (NULL);
	tmp = *save;
	while (*save)
	{
		while ((*save)->str[j])
			line[i++] = (*save)->str[j++];
		j = 0;
		*save = (*save)->next;
	}
	line[i] = '\0';
	*save = tmp;
	ft_free_lst(save);
	return (line);
}

char	*get_next_line(int fd)
{
	int			n_read;
	static char	buf[1024][BUFFER_SIZE + 1];
	char		*line;
	t_buf		*save;

	line = NULL;
	save = NULL;
	n_read = 0;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf[fd][0] == 0)
	{
		n_read = read(fd, buf[fd], BUFFER_SIZE);
		if (n_read <= 0)
			return (NULL);
	}
	line = get_line(fd, buf[fd], &save, n_read);
	return (line);
}
