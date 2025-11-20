/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:00:36 by yzhuang           #+#    #+#             */
/*   Updated: 2023/02/03 13:45:12 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_list
{
	char			*str;
	size_t			len;
	struct s_list	*next;
}	t_buf;

size_t	is_line(char *s);
void	ft_laddback(t_buf **lst, t_buf *new);
size_t	ft_lstlen(t_buf **lst);
void	ft_free_lst(t_buf **lst);
void	update_buf(int i, char *buf);
char	*save_buf(char *buf, int n_read, char *str, size_t n);
void	build_new(t_buf **save, char *buf, int n_read, size_t n);
void	build_save(int fd, t_buf **save, char *buf, int n_read);
char	*get_line(int fd, char *buf, t_buf **save, int n_read);
char	*get_next_line(int fd);

#endif