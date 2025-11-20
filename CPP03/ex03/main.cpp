/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:19:33 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 23:21:20 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main( void ) {

	DiamondTrap Diamond("TheDiamond");

	std::cout << "\n***" << std::endl;
	Diamond.highFivesGuys();
	Diamond.guardGate();
	
	std::cout << "\n***" << std::endl;
	Diamond.get_state();
	Diamond.attack("someone");
	Diamond.get_state();
	Diamond.takeDamage(30);
	Diamond.get_state();
	Diamond.beRepaired(30);
	Diamond.get_state();
	std::cout << "\n***" << std::endl;
	
	Diamond.whoAmI();
	std::cout << "\n***" << std::endl;
	return 0; 
}