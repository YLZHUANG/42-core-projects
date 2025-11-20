/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:32:36 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 18:33:07 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) { }

AMateria::~AMateria(void) { }

AMateria::AMateria(std::string const & type) : _type(type) { }

AMateria::AMateria( AMateria const & rhs ) {
	*this = rhs;
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria& AMateria::operator=(AMateria const &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

std::string const & AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharacter& target) {
	(void) target;
}
