/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:08:04 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 14:14:43 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {

	std::cout << "Tests with integers: \n" << std::endl;
	
	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 10), Point(0, 5) :" << std::endl;
	std::cout << bsp(Point(Fixed(-5), Fixed(0)), Point(Fixed(5), Fixed(0)), Point(Fixed(0), Fixed(10)), Point(Fixed(0), Fixed(5))) << std::endl;

	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 5), Point(1, 1) :" << std::endl;
	std::cout << bsp(Point(Fixed(-5), Fixed(0)), Point(Fixed(5), Fixed(0)), Point(Fixed(0), Fixed(5)), Point(Fixed(1), Fixed(1))) << std::endl;

	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 10), Point(1, 1) :" << std::endl;
	std::cout << bsp(Point(Fixed(-5), Fixed(0)), Point(Fixed(5), Fixed(0)), Point(Fixed(0), Fixed(10)), Point(Fixed(1), Fixed(1))) << std::endl;

	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 10), Point(0, 15) :" << std::endl;
	std::cout << bsp(Point(Fixed(-5), Fixed(0)), Point(Fixed(5), Fixed(0)), Point(Fixed(0), Fixed(10)), Point(Fixed(0), Fixed(15))) << std::endl;

	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 10), Point(20, 5) :" << std::endl;
	std::cout << bsp(Point(Fixed(-5), Fixed(0)), Point(Fixed(5), Fixed(0)), Point(Fixed(0), Fixed(10)), Point(Fixed(20), Fixed(5))) << std::endl;

	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 10), Point(4, 0) :" << std::endl;
	std::cout << bsp(Point(Fixed(-5), Fixed(0)), Point(Fixed(5), Fixed(0)), Point(Fixed(0), Fixed(10)), Point(Fixed(4), Fixed(0))) << std::endl;

	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 10), Point(4, -4) :" << std::endl;
	std::cout << bsp(Point(Fixed(-5), Fixed(0)), Point(Fixed(5), Fixed(0)), Point(Fixed(0), Fixed(10)), Point(Fixed(4), Fixed(-4))) << std::endl;


	std::cout << "\nSame tests with float point numbers: \n" << std::endl;
   
	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 10), Point(0, 5) :" << std::endl;
	std::cout << bsp(Point(-5.0f, 0.0f), Point(5.0f, 0.0f), Point(0.0f, 10.0f), Point(0.0f, 5.0f)) << std::endl;

	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 5), Point(1, 1) :" << std::endl;
	std::cout << bsp(Point(-5.0f, 0.0f), Point(5.0f, 0.0f), Point(0.0f, 5.0f), Point(1.0f, 1.0f)) << std::endl;

	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 10), Point(1, 1) :" << std::endl;
	std::cout << bsp(Point(-5.0f, 0.0f), Point(5.0f, 0.0f), Point(0.0f, 10.0f), Point(1.0f, 1.0f)) << std::endl;

	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 10), Point(0, 15) :" << std::endl;
	std::cout << bsp(Point(-5.0f, 0.0f), Point(5.0f, 0.0f), Point(0.0f, 10.0f), Point(0.0f, 15.0f)) << std::endl;

	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 10), Point(20, 5) :" << std::endl;
	std::cout << bsp(Point(-5.0f, 0.0f), Point(5.0f, 0.0f), Point(0.0f, 10.0f), Point(20.0f, 5.0f)) << std::endl;

	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 10), Point(4, 0) :" << std::endl;
	std::cout << bsp(Point(-5.0f, 0.0f), Point(5.0f, 0.0f), Point(0.0f, 10.0f), Point(4.0f, 0.0f)) << std::endl;

	std::cout << "Point(-5, 0), Point(5, 0), Point(0, 10), Point(4, -4) :" << std::endl;
	std::cout << bsp(Point(-5.0f, 0.0f), Point(5.0f, 0.0f), Point(0.0f, 10.0f), Point(4.0f, -4.0f)) << std::endl;

	return (0);
}
