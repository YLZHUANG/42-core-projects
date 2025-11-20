/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:11:16 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 14:12:08 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
}

Point::Point(const float x1, const float y1) : x(Fixed(x1)), y(Fixed(y1)) {
}

Point::Point(const Fixed x1, const Fixed y1) : x(x1), y(y1) {
}

Point::~Point( void ) {
}

Point::Point(Point const & rhs): x(rhs.getX()), y(rhs.getY()) {
}

Point& Point::operator=(const Point& other) {

	if (this != &other) {
		Fixed *px = (Fixed *)&x;
		Fixed *py = (Fixed *)&y;
		*px = x;
		*py = y;}
	return (*this);
}

const Fixed& Point::getX( void ) const {

	return (x);
}

const Fixed& Point::getY( void ) const {

	return (y);
}

Fixed Point::crossProduct( Point const & other ) const {

	return (x * other.getY() - y * other.getX());
}
