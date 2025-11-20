/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:45:48 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 16:58:12 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog") {

	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog( Dog const & rhs ) : Animal(rhs) {

	*this = rhs;
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog(void) {

	std::cout << "Dog destructor called." << std::endl;
}

Dog& Dog::operator=(Dog const &other) {
	
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

void Dog::makeSound(void) const {

	std::cout << "Whooofff" << std::endl;
}
