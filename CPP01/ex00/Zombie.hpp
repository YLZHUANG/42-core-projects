/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:09:23 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 13:31:11 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie {

public:

	Zombie( std::string name );
	~Zombie( void );
	
	void	announce( void ) const;

private:

	std::string	_name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif