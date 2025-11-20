/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:46:35 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:00:53 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon {

public:

	Weapon(	std::string othertype );
	Weapon(	void );
	~Weapon( void );

	const std::string&	getType( void ) const;
	void				setType( std::string other);

private:

	std::string	type;
};

#endif
