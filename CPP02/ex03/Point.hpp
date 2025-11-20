/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:10:14 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 14:12:02 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {

public:

	Point( void );
	~Point( void );
	Point( const float x1, const float y1 );
	Point( const Fixed x1, const Fixed y1 );
	Point( Point const & rhs );
	Point& operator=( Point const & other );

	const Fixed&	getX( void ) const;
	const Fixed&	getY( void ) const;
	Fixed			crossProduct( Point const & other ) const;

private:

	const Fixed	x;
	const Fixed	y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
