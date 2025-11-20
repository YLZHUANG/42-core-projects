/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:06:45 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 20:11:05 by yzhuang          ###   ########.fr       */
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
	
	Fixed&	operator=( Fixed const & other );
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:

	int					_value;
	static const int	_fract;
};

std::ostream& operator<<( std::ostream& o, Fixed const &fixed );

#endif
