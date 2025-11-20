/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:23:49 by yzhuang           #+#    #+#             */
/*   Updated: 2022/12/02 16:11:35 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}
*/
size_t	nword(char const *str, char c)
{
	size_t	i;
	size_t	s;
	size_t	n;

	i = 0;
	s = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] != c && s == 0)
		{
			s++;
			n++;
		}
		if (str[i] == c)
			s = 0;
		i++;
	}
	return (n);
}

char	*ft_strndup(const char *str, size_t n)
{
	char		*new;
	size_t		i;

	new = (char *)malloc(sizeof(char) * (n + 1));
	if (!new)
		return (NULL);
	new[n] = '\0';
	i = 0;
	while (i < n)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

char	**newstr(char const *s, char c, char **new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (i)
			{
				new[j] = ft_strndup(s, i);
				if (new[j] == NULL)
					free(new[j]);
				j++;
			}
			s += i + 1;
			i = 0;
		}
		else
			i++;
	}
	if (i)
		new[j] = ft_strndup(s, i);
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;

	new = (char **)malloc(sizeof(char *) * (nword(s, c) + 1));
	if (new == NULL)
		return (NULL);
	new[nword(s, c)] = 0;
	if (newstr(s, c, new) == NULL)
		return (NULL);
	return (new);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**new = ft_split(" this is new ", ' ');
//	char	**new = ft_split("", ' ');
	size_t	i = 0;

	while (i < nword(" this is new ", ' '))
//	while (i < nword("", ' '))
	{
		printf("%s\n", new[i]);
		i++;
	}
	free(new);
	return (0);
}*/
