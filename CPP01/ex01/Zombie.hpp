/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:16:59 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 13:33:33 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie {
	
public:

	Zombie( std::string name );
	Zombie( void );
	~Zombie( void );
	
	void	announce( void ) const;
	void	set_name( std::string name );

private:

	std::string	_name;
};

Zombie*	zombieHorde( int N, std::string name );

#endif
