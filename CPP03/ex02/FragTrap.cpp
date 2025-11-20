/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:45:11 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 21:54:46 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {

	_name = "frag";
	_hit_pts = 100;
	_energy_pts = 100;
	_attack_dmg = 30;
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {

	_hit_pts = 100;
	_energy_pts = 100;
	_attack_dmg = 30;
	std::cout << "FragTrap assignment constructor called." << std::endl;
}

FragTrap::FragTrap( FragTrap const & rhs ) {

	*this = rhs;
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap::~FragTrap(void) {

	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const & other) {
	
	if (this != &other) {
		_name = other._name;
		_hit_pts = other._hit_pts;
		_energy_pts = other._energy_pts;
		_attack_dmg = other._attack_dmg;
	}
	return (*this);
}

void FragTrap::attack(const std::string& target) {

	if (!_hit_pts || !_energy_pts)
		std::cout << "FragTrap " << _name << " has no hit points or energy points left! No action possible!" << std::endl;
	else {
		_energy_pts--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_dmg << " points of damage!" << std::endl; }
	std::cout << "\e[32mSTATE of " << _name << " : " << _hit_pts << " hit points; " << _energy_pts << " energy points.\e[0m" << std::endl;	
}

void FragTrap::highFivesGuys(void) {

	std::cout << "FragTrap " << _name << " : Give me a high fives, guys! " << std::endl;
}
