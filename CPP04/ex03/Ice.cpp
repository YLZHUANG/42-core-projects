/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:36:54 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 18:37:02 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::~Ice(void) {}

Ice::Ice(std::string const & type) : AMateria(type) {}

Ice::Ice( Ice const & rhs ) : AMateria("ice") {
	*this = rhs;
}

Ice& Ice::operator=(Ice const &other) {
	if (this != &other) {
		this->_type = other._type; }
	return (*this);
}

Ice* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
