/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:52:53 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 18:09:47 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {

	int i;
	for (i = 0; i < 100; i++) {
		i % 2 ? ideas[i] = "Another meal?" : ideas[i] = "Another nap?";}
	std::cout << "Brain default constructor called." << std::endl; 
}

Brain::Brain( Brain const & rhs ) {

	*this = rhs;
	std::cout << "Brain copy constructor called." << std::endl;
}

Brain::~Brain(void) {

	std::cout << "Brain destructor called." << std::endl;
}

Brain& Brain::operator=(Brain const &other) {
	
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

const std::string& Brain::getIdea( void ) const {

	return (ideas[rand() % 101]);
}
