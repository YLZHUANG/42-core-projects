/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:09:17 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 13:28:10 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {
	
	{
		std::cout << "*** Given tests ***" << std::endl;
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		
		a = Fixed( 1234.4321f );
		
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
		
	}
	{
		std::cout << "***" << std::endl;
		std::cout << "\n*** My tests ***" << std::endl;
		Fixed const m( -32.54f );
		Fixed const n( -32.543f );
		Fixed const e( 42.42345678999999999999999999999f );
		Fixed const f( 42.423f );
		Fixed const g( 42.4234f );
		Fixed const h( 42.42345f );

		std::cout << "-32.54f is " << m << " as float, " << m.toInt() << " as integer" << std::endl;
		std::cout << "-32.543f is " << n << " as float, " << n.toInt() << " as integer" << std::endl;
		std::cout << "42.42345678999999999999999999999f is " << e << " as float, " << e.toInt() << " as integer" << std::endl;
		std::cout << "42.423f is " << f << " as float, " << f.toInt() << " as integer" << std::endl;
		std::cout << "42.4234f is " << g << " as float, " << g.toInt() << " as integer" << std::endl;
		std::cout << "42.42345f is " << h << " as float, " << h.toInt() << " as integer" << std::endl;
	}
	return 0;
}
