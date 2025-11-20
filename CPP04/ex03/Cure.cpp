/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:35:57 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 18:36:16 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::~Cure(void) {}

Cure::Cure(std::string const & type) : AMateria(type) {}

Cure::Cure( Cure const & rhs ) : AMateria("cure") {
	*this = rhs;
}

Cure& Cure::operator=(Cure const &other) {
	if (this != &other) {
		this->_type = other._type; }
	return (*this);
}

Cure* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
