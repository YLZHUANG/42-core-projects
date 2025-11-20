/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:43:37 by yzhuang           #+#    #+#             */
/*   Updated: 2024/11/27 12:47:36 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Try to initiate a >>>>>" << std::endl;
	Bureaucrat a("a", 149);
	std::cout << a << std::endl;
	
	std::cout << "Try to initiate b with -20 grade >>>>>" << std::endl;
	Bureaucrat b("b", -20);
	std::cout << b << std::endl;
	
	std::cout << "Try to initiate c with 200 grade >>>>>" << std::endl;
	Bureaucrat c("c", 200);
	std::cout << c << std::endl;
	
	std::cout << "Try to create a copy of a >>>>>" << std::endl;
	Bureaucrat d(a);
	std::cout << d << std::endl;
	
	std::cout << "make b = a >>>>>" << std::endl;
	b = a;
	std::cout << b << std::endl;
	
	std::cout << "Try to initiate a default bureaucrat >>>>>" << std::endl;
	Bureaucrat x;
	std::cout << x << std::endl;

	std::cout << "Get a's name: " << a.getName() << std::endl;
	std::cout << "Get a's grade: " << a.getGrade() << std::endl;

	std::cout << "\nTry to decrement a's grade >>>>>" << std::endl;
	--a;
	std::cout << a << std::endl;

	std::cout << "Try to decrement a's grade >>>>>" << std::endl;
	--a;
	std::cout << a << std::endl;

	std::cout << "Set a's grade to 1 >>>>>" << std::endl;
	a.setGrade(1);
	std::cout << a << std::endl;

	std::cout << "Try to increment a's grade >>>>>" << std::endl;
	++a;
	std::cout << a << std::endl;

	return (0);
}
