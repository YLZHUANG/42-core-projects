/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:44:22 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:05:48 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string other_n ) : name(other_n) {

	weapon = NULL;
}

HumanB::~HumanB( void ) {
}

void	HumanB::attack( void ) const {

	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon " << std::endl;
}

void HumanB::setWeapon( Weapon &otherweapon ) {

	this->weapon = &otherweapon;
}
