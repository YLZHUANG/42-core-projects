/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:37:27 by yzhuang           #+#    #+#             */
/*   Updated: 2024/12/09 12:56:27 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T t;

	t = a;
	a = b;
	b = t;
}

template<typename T>
T const	&min(T const &a, T const &b)
{
	return (a >= b ? b : a);
}

template<typename T>
T const	&max(T const &a, T const &b)
{
	return (a <= b ? b : a);
}

#endif
