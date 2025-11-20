/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:52:25 by yzhuang           #+#    #+#             */
/*   Updated: 2022/11/30 12:44:19 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*If there is an error, they return a NULL pointer and set errno to
     ENOMEM.*/

#include "libft.h"
//#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*s;

	i = 0;
	if (nmemb > 0 && (size * nmemb) / nmemb != size)
		return (NULL);
	s = malloc(size * nmemb);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size * nmemb);
	return (s);
}
