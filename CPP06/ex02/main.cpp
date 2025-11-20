/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:09:59 by yzhuang           #+#    #+#             */
/*   Updated: 2024/12/09 12:24:56 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

 Base *generate(void)
 {
	int i = rand() % 3;

	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	else
		return (new C());
 }

 void identify(Base* p)
 {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type." << std::endl;
 }

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception&)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception&)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(const std::exception&)
			{
				std::cout << "Unknown type." << std::endl;
			}
		}
	}
}

int main(void) {

	try
	{
		srand(static_cast<unsigned int>(time(0)));
		Base* p;

		std::cout << "<<<<<<<<<<<<<<<<<<<<< TEST 1" << std::endl;
		std::cout << "<<<<<< Randomly generating a Base" << std::endl;
		p = generate();
		std::cout << "<<<<<< Identify pointer" << std::endl;
		identify(p);
		std::cout << "<<<<<< Identify reference" << std::endl;
		identify(*p);
		std::cout << "<<<<<< Identify other type" << std::endl;
		std::cout << std::endl;
		delete p;

		std::cout << "<<<<<<<<<<<<<<<<<<<<< TEST 2" << std::endl;
		std::cout << "<<<<<< Randomly generating a Base" << std::endl;
		p = generate();
		std::cout << "<<<<<< Identify pointer" << std::endl;
		identify(p);
		std::cout << "<<<<<< Identify reference" << std::endl;
		identify(*p);
		std::cout << std::endl;
		delete p;

		std::cout << "<<<<<<<<<<<<<<<<<<<<< TEST 3" << std::endl;
		std::cout << "<<<<<< Randomly generating a Base" << std::endl;
		p = generate();
		std::cout << "<<<<<< Identify pointer" << std::endl;
		identify(p);
		std::cout << "<<<<<< Identify reference" << std::endl;
		identify(*p);
		delete p;
		// std::cout << "\n<<<<<< Generating a unknown Base" << std::endl;
		// Base *p2 = new X();
		// std::cout << "<<<<<< Identify pointer" << std::endl;
		// identify(p2);
		// std::cout << "<<<<<< Identify reference" << std::endl;
		// identify(*p2);
		// delete p2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
