/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:46:20 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 15:46:22 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	std::cout << "\n*** Given tests ***" << std::endl; 
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl; 
	i->makeSound(); //will output the cat sound! 
	j->makeSound();
	meta->makeSound();

	std::cout << "\n*** Copy constructor tests ***" << std::endl; 
	const Animal* copy_j = new Dog(*static_cast<const Dog*>(j));
	const Animal* copy_i = new Cat(*static_cast<const Cat*>(i));
	std::cout << copy_j->getType() << " " << std::endl;
	std::cout << copy_i->getType() << " " << std::endl;
	copy_i->makeSound();
	copy_j->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	delete copy_j;
	delete copy_i;

	std::cout << "\n*** WrongAnimal tests ***" << std::endl; 
	const WrongAnimal* wrong_meta = new WrongAnimal(); 
	const WrongAnimal* wrong_i = new WrongCat();
	const WrongCat* wrong_j = new WrongCat();

	std::cout << "*** WrongCat created with WrongAnimal" << std::endl;
	std::cout << wrong_i->getType() << " " << std::endl; 
	wrong_i->makeSound(); //will output the WrongAnimal sound! 

	std::cout << "*** WrongCat created with WrongCat" << std::endl;
	std::cout << wrong_j->getType() << " " << std::endl; 
	wrong_j->makeSound(); //will output the WrongCat sound! 

	std::cout << "*** WrongAnimal" << std::endl;
	std::cout << wrong_meta->getType() << " " << std::endl; 
	wrong_meta->makeSound();

	std::cout << std::endl;
	delete wrong_meta;
	delete wrong_i;
	delete wrong_j;

return 0; }
