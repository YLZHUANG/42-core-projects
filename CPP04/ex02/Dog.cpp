/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:45:48 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 18:22:46 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog") {

	brain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog( Dog const & rhs ) : Animal(rhs) {

	*this = rhs;
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog(void) {

	delete brain;
	std::cout << "Dog destructor called." << std::endl;
}

Dog& Dog::operator=(Dog const &other) {
	
	if (this != &other) {
		this->type = other.type;
		brain = new Brain(*other.brain); }
	return *this;
}

void Dog::makeSound(void) const {

	std::cout << "Whooofff" << std::endl;
}

void Dog::checkIdea( void ) const {

	std::cout << "Idea of the moment: " << brain->getIdea() << std::endl;
}
