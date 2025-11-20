/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:45:36 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 15:59:19 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

public:

	Cat( void );
	Cat( Cat const & rhs );
	virtual ~Cat( void );
	
	Cat&			operator=(Cat const & other);
	virtual void	makeSound( void ) const;
	void			checkIdea( void ) const;

private:

	Brain *brain;
};

#endif
