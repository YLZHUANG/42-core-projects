/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:37:11 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 18:37:12 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
	
public:

	Ice( void );
	virtual ~Ice( void );
	Ice(std::string const & type);
	Ice( Ice const & rhs );
	Ice& operator=(Ice const & other);

	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};

#endif
