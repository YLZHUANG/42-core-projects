/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:49:03 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 21:53:34 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	incre_decre(unsigned int *nb, int incre, unsigned int to_add) {

	if (incre) {
		if ((*nb + to_add) > UINT_MAX)
			*nb = UINT_MAX;}
	else {
		if (to_add > *nb)
			*nb = 0;
	}
}

int	main( void ) { 

	FragTrap a("a");
	FragTrap b("b");
	unsigned int a_hp = 100;
	unsigned int a_ep = 100;
	unsigned int b_hp = 100;
	unsigned int b_ep = 100;

	b.highFivesGuys();
	std::cout << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << "*** Round " << i + 1 << " ***" << std::endl;
		a.attack("b");
		incre_decre(&a_ep, 0, 1);
		if (a_hp && a_ep) {
			b.takeDamage(30);
			incre_decre(&b_hp, 0, 30);}
		b.beRepaired(1);
		incre_decre(&b_hp, 1, 1);
		incre_decre(&b_ep, 0, 1);}

	std::cout << "***\n" << std::endl;
	a.attack("someone else");
	incre_decre(&a_ep, 0, 1);
	b.attack("a");
	incre_decre(&b_ep, 0, 1);
	if (b_hp && b_ep) {
		a.takeDamage(30);
		incre_decre(&a_hp, 0, 30);}
	std::cout << "***\n" << std::endl;
	return 0; 
}