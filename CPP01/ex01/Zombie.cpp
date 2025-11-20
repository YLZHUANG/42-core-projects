/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:15:44 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 13:33:24 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {
}

Zombie::~Zombie(void) {
	
	std::cout << this->_name << " is destroyed \U0001F4A3\U0001F4A5 RIP+" << std::endl;
}

void	Zombie::set_name( std::string name ) {

	_name = name;
}

void	Zombie::announce(void) const {

	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( void ) {}
