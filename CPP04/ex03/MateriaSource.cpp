/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:39:59 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 18:40:41 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	
	for (int i = 0; i < 4; i++) {
		_materia[i] = 0; }
}

MateriaSource::~MateriaSource(void) {
	
	for (int i = 0; i < 4; i++) {
		if (_materia[i])
			delete _materia[i];
		else
			return; }
}

MateriaSource::MateriaSource( MateriaSource const & rhs ) {
	*this = rhs;
}

MateriaSource& MateriaSource::operator=(MateriaSource const &other) {
	
	if (this != &other) {
		for (int i = 0; i < 4; i++)
			_materia[i] = other._materia[i]; }
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m) {

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

AMateria*	MateriaSource::createMateria(std::string const & type) {

	for (int i = 0; i < 4; i++) 
	{
		if (_materia[i] && _materia[i]->getType() == type)
			return (_materia[i]->clone());
	}
	return (NULL);
}
