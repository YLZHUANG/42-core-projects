/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:38:06 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 20:35:02 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {

	std::cout << "*** Given tests ***" << std::endl;
	IMateriaSource* src = new MateriaSource(); 
	src->learnMateria(new Ice()); 
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob"); 
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "\n*** More tests ***" << std::endl;
	IMateriaSource* src2 = new MateriaSource(); 
	src2->learnMateria(new Ice()); 
	src2->learnMateria(new Ice()); 
	src2->learnMateria(new Ice()); 
	src2->learnMateria(new Cure());  
	src2->learnMateria(new Ice()); // No effet, no crash and no leak
	src2->learnMateria(new Cure()); // No effet, no crash and no leak

	ICharacter* person = new Character("person");
	ICharacter* pop = new Character("pop");
	ICharacter* nop = new Character("nop");
	AMateria* tmp2;
	tmp2 = src2->createMateria("ice");
	person->equip(tmp2);
	tmp2 = src2->createMateria("else");  // No effet, no crash and no leak
	person->equip(tmp2);
	tmp2 = src2->createMateria("cure");
	person->equip(tmp2);
	tmp2 = src2->createMateria("cure");
	person->equip(tmp2);
	tmp2 = src2->createMateria("cure");
	person->equip(tmp2);
	tmp2 = src2->createMateria("cure"); // No effet, no crash and no leak
	person->equip(tmp2);
	tmp2 = src2->createMateria("else"); // No effet, no crash and no leak

	person->use(0, *pop);
	person->use(1, *pop);
	person->use(2, *pop); 
	person->use(3, *pop); 
	person->use(4, *nop); // No effet, no crash and no leak
	person->use(5, *pop); // No effet, no crash and no leak

	delete person;
	delete pop;
	delete nop;
	delete src2;

	return 0;
}