/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:59:22 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 20:37:16 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) {
		for (int i = 0; i < 4; i++) {
		_materia[i] = 0; }
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (_materia[i])
			delete _materia[i];
		else
			return; }
}

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_materia[i] = 0; }
}

Character::Character( Character const & rhs ) {
	*this = rhs;
}

Character& Character::operator=(Character const &other) {
	if (this != &other) {
		this->_name = other._name; 
		for (int i = 0; i < 4; i++) {
			if (_materia[i]) {
				delete _materia[i];
				_materia[i] = 0;}
			_materia[i] = other._materia[i]->clone(); } }
	return *this;
}

std::string const & Character::getName() const {
	return (_name);
}

void Character::equip(AMateria* m) {	
	for (int i = 0; i < 4; i++) 
	{
		if (!_materia[i])
		{
			_materia[i] = m;
			return;
		}
	}
	delete m;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4)
		_materia[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4) {
		if (_materia[idx])
			_materia[idx]->use(target);
	}
}
