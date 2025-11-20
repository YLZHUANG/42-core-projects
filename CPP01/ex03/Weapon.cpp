/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:46:23 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:01:11 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) {
}

Weapon::Weapon(	std::string othertype) : type(othertype) {
}

Weapon::~Weapon( void ) {
}

const std::string&	Weapon::getType( void ) const{

	return (this->type);
}

void	Weapon::setType( std::string other) {

	this->type = other;
}
