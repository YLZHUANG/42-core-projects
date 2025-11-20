/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:23:02 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 12:54:01 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {

public:

	Fixed( void );
	Fixed( Fixed const & rhs );
	~Fixed( void );

	Fixed&	operator=(Fixed const & other);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:

	int					_value;
	static const int	_fract;
};

#endif
