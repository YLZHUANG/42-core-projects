/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:34:35 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 15:40:33 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {

	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string name) : type(name) {

	std::cout << "Animal assignment constructor called." << std::endl;
}

Animal::Animal( Animal const & rhs ) {

	*this = rhs;
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal(void) {

	std::cout << "Animal destructor called." << std::endl;
}

Animal& Animal::operator=(Animal const &other) {
	
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

std::string	Animal::getType( void ) const {

	return (type);
}

void Animal::makeSound(void) const {
	
	std::cout << "WHATTTTT" << std::endl;
}
