/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:31:59 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 13:32:40 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	const Fixed::_fract = 8;

Fixed::Fixed(void) : _value(0) {
}

Fixed::Fixed( Fixed const & rhs ) {

	*this = rhs;
}

Fixed::Fixed(const int value) : _value(value << _fract) {
}

Fixed::Fixed(const float value) : _value(roundf((value * (1 << _fract)))) {
}

Fixed::~Fixed(void) {
}

int Fixed::getRawBits( void ) const {

	return (_value);
}

void Fixed::setRawBits( int const raw ) {

	_value = raw;
}

Fixed& Fixed::operator=(Fixed const & other) {
	
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

bool	Fixed::operator>(Fixed const & other) const {

	return (_value > other.getRawBits());
}

bool	Fixed::operator<(Fixed const & other) const {

	return (_value < other.getRawBits());
}

bool	Fixed::operator==(Fixed const & other) const {

	return (_value == other.getRawBits());
}

bool	Fixed::operator>=(Fixed const & other) const {

	return (_value >= other.getRawBits());
}

bool	Fixed::operator<=(Fixed const & other) const {

	return (_value <= other.getRawBits());
}

bool	Fixed::operator!=(Fixed const & other) const {

	return (_value != other.getRawBits());
}

Fixed	Fixed::operator+(Fixed const & other) const {

	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(Fixed const & other) const {

	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(Fixed const & other) const {

	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(Fixed const & other) const {

	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed&	Fixed::operator++(void) {

	++_value;
	return (*this);
}

Fixed	Fixed::operator++(int) {

	Fixed curr(*this);
	_value++;
	return (curr);
}

Fixed&	Fixed::operator--(void) {

	--_value;
	return (*this);
}

Fixed	Fixed::operator--(int) {

	Fixed curr(*this);
	_value--;
	return (curr);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {

	if (a <= b)
		return (a);
	return (b);
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b) {

	if (a <= b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {

	if (a >= b)
		return (a);
	return (b);
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b) {

	if (a >= b)
		return (a);
	return (b);
}
