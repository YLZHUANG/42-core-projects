/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:03:02 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 14:03:07 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {

		std::cout << "*** Given tests ***" << std::endl;Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
		std::cout << "***" << std::endl;

		std::cout << "\n*** My tests ***" << std::endl;
		std::cout << "Min between " << a << " and " << b << " is " << Fixed::min( a, b ) << std::endl;
		a = Fixed(4.2f);
		Fixed c = Fixed(8.4f);
		std::cout << "Max between " << a << " and " << c << " is " << Fixed::max( a, c ) << std::endl;
		std::cout << a << " + " << c << " = " << a + c << std::endl;
		std::cout << a << " - " << c << " = " << a - c << std::endl;
		std::cout << a << " * " << c << " = " << a * c << std::endl;
		std::cout << a << " / " << c << " = " << a / c << std::endl;

	return 0;
}
