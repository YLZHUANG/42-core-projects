/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:35:20 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 18:27:34 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal {

public:
	Animal( void );
	Animal( std::string name );
	Animal( Animal const & rhs );
	virtual ~Animal( void );

	Animal& operator=(Animal const & other);
	virtual void makeSound( void ) const = 0;
	std::string	getType( void ) const;

protected:

	std::string	type;
};

#endif
