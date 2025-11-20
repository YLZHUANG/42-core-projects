/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:45:09 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 18:21:40 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat") {

	brain = new Brain();
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat( Cat const & rhs ) : Animal(rhs) {

	*this = rhs;
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat(void) {

	delete brain;
	std::cout << "Cat destructor called." << std::endl;
}

Cat& Cat::operator=(Cat const &other) {
	
	if (this != &other) {
		this->type = other.type;
		brain = new Brain(*other.brain); 
	}
	return *this;
}

void Cat::makeSound(void) const {

	std::cout << "Meowwwww" << std::endl;
}

void Cat::checkIdea( void ) const {

	std::cout << "Idea of the moment: " << brain->getIdea() << std::endl;
}
