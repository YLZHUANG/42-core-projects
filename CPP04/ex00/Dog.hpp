/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:46:07 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 15:46:08 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal {

public:

	Dog( void );
	Dog( Dog const & rhs );
	virtual	~Dog( void );

	Dog&			operator=(Dog const & other);
	virtual void	makeSound( void ) const;
};

#endif
