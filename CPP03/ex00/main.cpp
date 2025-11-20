/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:56:02 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 20:49:04 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void ) { 

	ClapTrap a("a");
	ClapTrap b("b");
	unsigned int hp = 100;
	unsigned int ep = 50;
	unsigned int a_ep = 50;

	for (int i = 0; i < 3; i++) {
	std::cout << "\n*** Round " << i + 1 << " ***" << std::endl;
	a.attack("b");
	a_ep--;
	b.takeDamage(0);
	b.beRepaired(1);
	hp++;
	ep--;}
	std::cout << "***\n" << std::endl;

	std::cout << "*** A ClapTrap attacks b, a attacks someone else, b attacks a ***" << std::endl;
	ClapTrap d;
	d.attack("b");
	b.takeDamage(0);
	a.attack("someone else");
	a_ep--;
	b.attack("a");
	ep--;
	if (hp && ep)
		a.takeDamage(0);
		
	std::cout << "***\n\n*** Someone strongly attacked b, then b tries to attack a ***" << std::endl;
	b.takeDamage(100);
	b.attack("a");
	std::cout << "***\n" << std::endl;

	std::cout << "*** Randome attacks ***" << std::endl;
	ClapTrap c = a;
	c.attack("someone");
	std::cout << "***\n" << std::endl;
	return 0; 
}