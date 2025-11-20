/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:46:31 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 15:46:36 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {

	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type(name) {

	std::cout << "WrongAnimal assignment constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & rhs ) {

	*this = rhs;
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(void) {

	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

std::string	WrongAnimal::getType( void ) const {

	return (type);
}

void WrongAnimal::makeSound(void) const {

	std::cout << "WHATTTTT" << std::endl;
}
