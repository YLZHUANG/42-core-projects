/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:36:57 by yzhuang           #+#    #+#             */
/*   Updated: 2024/12/09 12:56:36 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main( void ) { 

	try
	{
		std::cout << "<<<<<<<<<<<<<<<<<<<< Required tests >>>>>>>>>>>>>>>>>>>>" << std::endl;	
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

		std::cout << "<<<<<<<<<<<<<<<<<<<< More tests >>>>>>>>>>>>>>>>>>>>" << std::endl;
		char e = 'e';
		char f = 'f';
		std::cout << "e = " << e << ", f = " << f << std::endl;
		std::cout << "min( e, e) = " << ::min( e, e ) << std::endl;
		::swap( e, f );
		std::cout << "<<<< Swapping " << std::endl;
		std::cout << "e = " << e << ", f = " << f << std::endl;

		std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
		std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0; }
