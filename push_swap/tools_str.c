/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:35:20 by yzhuang           #+#    #+#             */
/*   Updated: 2023/05/30 17:36:45 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	if (!s)
		return (c);
	while (s[c])
		c++;
	return (c);
}

void	ft_strcpy(char *s1, char *s2, char *new, int i)
{
	size_t	j;

	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	new[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	ft_strcpy(s1, s2, new, i);
	if (s1)
		free(s1);
	return (new);
}

char	*cut_join(char *s1, char *s2, int cut, int tsize)
{
	int		i;
	int		j;
	int		size1;
	char	*news;

	i = 0;
	j = 0;
	size1 = ft_strlen(s1) - cut;
	news = malloc(sizeof(char) * (size1 + tsize + 1));
	if (!news)
		return (NULL);
	while (i < size1)
	{
		news[i] = s1[i];
		i++;
	}
	while (tsize)
	{
		news[i++] = s2[j++];
		tsize--;
	}
	news[i] = '\0';
	if (s1)
		free(s1);
	return (news);
}
