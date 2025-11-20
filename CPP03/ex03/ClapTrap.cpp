/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:37:59 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 23:02:38 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("clap"), _hit_pts(10), _energy_pts(10), _attack_dmg(0) {

	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_pts(10), _energy_pts(10), _attack_dmg(0) {

	std::cout << "ClapTrap assignment constructor called." << std::endl;
	std::cout << name << " is created." << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & rhs ) {

	*this = rhs;
	std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap(void) {

	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & other) {
	
	if (this != &other) {
		_name = other._name;
		_hit_pts = other._hit_pts;
		_energy_pts = other._energy_pts;
		_attack_dmg = other._attack_dmg;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target) {

	if (!_hit_pts || !_energy_pts)
		std::cout << "ClapTrap " << _name << " has no hit points or energy points left! No action possible! " << std::endl;
	else {
		_energy_pts--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_dmg << " points of damage!" << std::endl; }
	//std::cout << "\e[32mSTATE of " << _name << " : " << _hit_pts << " hit points; " << _energy_pts << " energy points.\e[0m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (amount > _hit_pts) {
		std::cout << "ClapTrap " << _name << " was attacked, losing all its hit points!" << std::endl;
		std::cout << "\e[32mSTATE of " << _name << " : 0 hit points; " << _energy_pts << " energy points.\e[0m" << std::endl;
		_hit_pts = 0;
		return ;
	}
	_hit_pts -= amount;
	std::cout << "ClapTrap " << _name << " was attacked, losing " << amount << " points of damage!" << std::endl;
	//std::cout << "\e[32mSTATE of " << _name << " : " << _hit_pts << " hit points; " << _energy_pts << " energy points.\e[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (!_hit_pts || !_energy_pts) 
		std::cout << "ClapTrap " << _name << " has no hit points or energy points left! No action possible!" << std::endl;
	else {
		_energy_pts--;
		if (amount + _hit_pts > UINT_MAX) {
			_hit_pts = UINT_MAX;
			std::cout << "ClapTrap " << _name << " repairs itself, getting " <<  UINT_MAX - amount << " hit points back!" << std::endl;}
		else {
			_hit_pts += amount;
			std::cout << "ClapTrap " << _name << " repairs itself, getting " <<  amount << " hit points back!" << std::endl;}
	}
	//std::cout << "\e[32mSTATE of " << _name << " : " << _hit_pts << " hit points; " << _energy_pts << " energy points.\e[0m" << std::endl;	
}
