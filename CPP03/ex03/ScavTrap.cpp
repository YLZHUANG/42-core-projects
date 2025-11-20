/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:39:44 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 23:14:18 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {

	_name = "scav";
	_hit_pts = 100;
	_energy_pts = 50;
	_attack_dmg = 20;
	_energy = 50;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

	_hit_pts = 100;
	_energy_pts = 50;
	_attack_dmg = 20;
	_energy = 50;
	std::cout << "ScavTrap assignment constructor called." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & rhs ) {

	*this = rhs;
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap(void) {

	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & other) {
	
	if (this != &other) {
		_name = other._name;
		_hit_pts = other._hit_pts;
		_energy_pts = other._energy_pts;
		_attack_dmg = other._attack_dmg;
		_energy = other._energy;
	}
	return (*this);
}

void ScavTrap::guardGate(void) {

	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {

	if (!_hit_pts || !_energy_pts)
		std::cout << "ScavTrap " << _name << " has no hit points or energy points left! No action possible! " << std::endl;
	else {
		_energy_pts--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_dmg << " points of damage!" << std::endl; }
	//std::cout << "\e[32mSTATE of " << _name << " : " << _hit_pts << " hit points; " << _energy_pts << " energy points.\e[0m" << std::endl;	
}
