/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:32:53 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 13:33:46 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {

public:

	Fixed( void );
	Fixed( Fixed const & rhs );
	Fixed( int const value );
	Fixed( float const value );
	~Fixed( void );
	
	Fixed& operator=(Fixed const & other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	bool	operator>(Fixed const & other) const;
	bool	operator<(Fixed const & other) const;
	bool	operator==(Fixed const & other) const;
	bool	operator>=(Fixed const & other) const;
	bool	operator<=(Fixed const & other) const;
	bool	operator!=(Fixed const & other) const;

	Fixed	operator+(Fixed const & other) const;
	Fixed	operator-(Fixed const & other) const;
	Fixed	operator*(Fixed const & other) const;
	Fixed	operator/(Fixed const & other) const;

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(Fixed const & a, Fixed const & b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(Fixed const & a, Fixed const & b);

private:

	int					_value;
	static const int	_fract;
};

std::ostream& operator<<(std::ostream& o, Fixed const &fixed);

#endif
