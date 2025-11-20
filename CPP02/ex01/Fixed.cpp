/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:06:31 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 13:27:51 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	const Fixed::_fract = 8;

Fixed::Fixed(void) : _value(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & rhs ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::Fixed(const int value) : _value(value << _fract) {

	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf((value * (1 << _fract)))) {

	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {

	return (_value);
}

void Fixed::setRawBits( int const raw ) {

	_value = raw;
}

Fixed& Fixed::operator=(Fixed const & other) {
	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

float Fixed::toFloat( void ) const {

	return (static_cast<float>(_value) / (1 << _fract));
}

int Fixed::toInt( void ) const {

	return (_value >> _fract);
}

std::ostream& operator<<(std::ostream& o, Fixed const &fixed) {

	o << fixed.toFloat();
	return (o);
}
