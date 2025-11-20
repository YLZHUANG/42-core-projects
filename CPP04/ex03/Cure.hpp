/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:36:45 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 18:36:46 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
	
public:

	Cure( void );
	virtual ~Cure( void );
	Cure(std::string const & type);
	Cure( Cure const & rhs );
	Cure& operator=(Cure const & other);

	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};

#endif
