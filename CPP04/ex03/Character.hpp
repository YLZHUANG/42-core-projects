/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:34:44 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 20:18:40 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter {

protected:

	std::string	_name;
	AMateria	*_materia[4];
	
public:

	Character( void );
	Character(std::string const & name);
	Character( Character const & rhs );
	virtual ~Character( void );
	Character& operator=(Character const & other);
	
	virtual std::string const & getName() const;
	virtual void	equip(AMateria* m);
	virtual void	unequip(int idx);
	virtual void	use(int idx, ICharacter& target);

};

#endif
