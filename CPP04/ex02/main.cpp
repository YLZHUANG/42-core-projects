/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:44:04 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 18:31:49 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "\n*** Given tests ***" << std::endl; 	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "\n*** Described tests ***" << std::endl; 
	Animal* horde[10];
	size_t k;
	for (k = 0; k < 5; k++)
		horde[k] = new Dog();
	for (; k < 10; k++)
		horde[k] = new Cat();
	for (k = 0; k < 10; k++)
		delete horde[k];

	std::cout << "\n*** More dog tests ***" << std::endl; 
	Dog d1;
	Dog d2 = d1;
	d1.checkIdea();
	d2.checkIdea();
	d1.makeSound();
	d2.makeSound();

	std::cout << "\n*** More cat tests ***" << std::endl; 
	const Cat* c1 = new Cat();
	const Cat* c2 = new Cat(*c1);
	c1->checkIdea();
	c2->checkIdea();
	c1->makeSound();
	c2->makeSound();
	delete c1;
	delete c2;

	//std::cout << "*** Test Animal***" << std::endl;
	// const Animal* a = new Animal();
	// a->makeSound();
	// delete a;
	// Animal b;

	return 0;
}
