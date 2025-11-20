/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:17:08 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 13:17:15 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {
	
	if (N <= 0)
		return (NULL);
	
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].set_name(name);

	return horde;
};
