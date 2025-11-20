/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:09:09 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 13:31:17 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {
}

Zombie::~Zombie( void ) {
	
	std::cout << "Zombie " << this->_name << " is destroyed \U0001F4A3\U0001F4A5" << std::endl;
}

void	Zombie::announce( void ) const {

	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name ) {

	Zombie*	new_zombie = new Zombie(name);
	return (new_zombie);
}

void randomChump( std::string name ) {

	Zombie ram_chump(name);
	ram_chump.announce();
}
