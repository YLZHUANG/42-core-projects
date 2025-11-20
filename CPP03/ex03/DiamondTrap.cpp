/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:06:02 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 23:17:11 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {

	ClapTrap::_name = "DiamondTrap_clap_name";
	ClapTrap::_energy_pts = ScavTrap::_energy;
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name"), _name(name) {

	ClapTrap::_energy_pts = ScavTrap::_energy;
	std::cout << "DiamondTrap assignment constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & rhs) {

	*this = rhs;
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {

	std::cout << "DiamondTrap destructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & other) {
	
	if (this != &other) {
		_name = other._name;
		_hit_pts = other._hit_pts;
		_energy_pts = other._energy_pts;
		_attack_dmg = other._attack_dmg;
	}
	return (*this);
}

void DiamondTrap::whoAmI(void) {

	std::cout << "I am " << _name << ". My ClapTrap name is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::get_state(void){

	std::cout << "\e[32mSTATE of " << _name << " : " << _hit_pts << " hit points; " << _energy_pts << " energy points.\e[0m" << std::endl;	
}
