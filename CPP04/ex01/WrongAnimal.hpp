/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:46:53 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 15:46:58 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal {

public:

	WrongAnimal( void );
	WrongAnimal( std::string name );
	WrongAnimal( WrongAnimal const & rhs );
	virtual ~WrongAnimal( void );

	WrongAnimal&	operator=(WrongAnimal const & other);
	void			makeSound( void ) const;
	std::string		getType( void ) const;

protected:

	std::string	type;
};

#endif
