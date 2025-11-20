/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:08:51 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 13:13:54 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {

	Zombie *zom = newZombie("Zom");
	zom->announce();
	delete zom;
	
	randomChump("Ram");
	return (0);
}
