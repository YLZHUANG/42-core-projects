/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:39 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 15:47:54 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat") {

	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat( WrongCat const & rhs ) : WrongAnimal(rhs) {

	*this = rhs;
	std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat(void) {

	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const &other) {

	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

void WrongCat::makeSound(void) const {

	std::cout << "Meowwwww" << std::endl;
}
