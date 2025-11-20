/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:42:10 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:04:52 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string other_n, Weapon &other_w ) :
 name(other_n), weapon(other_w) {
}

HumanA::~HumanA( void ) {
}

void	HumanA::attack( void ) const {

	std::cout << this->name << " attacks with their " 
	<< this->weapon.getType() << std::endl;
}