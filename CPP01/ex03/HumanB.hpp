/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:44:28 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:05:39 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB {

public:

	HumanB( std::string other_n );
	~HumanB( void );

	void	attack( void ) const;
	void	setWeapon( Weapon &otherweapon );

private:
	
	std::string	name;
	Weapon		*weapon;
};

#endif
