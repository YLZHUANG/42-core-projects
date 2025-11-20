/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:43:31 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:04:57 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA {

public:

	HumanA( std::string other_n, Weapon &other_w );
	~HumanA( void );

	void attack( void ) const;

private:

	std::string name;
	Weapon &weapon;
};

#endif
