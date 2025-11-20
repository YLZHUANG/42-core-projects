/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:27:28 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:38:00 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# define NB_LEVELS 4

class Harl {
	
public:

	Harl( void );
	~Harl( void );

	void	complain( std::string level );

private:

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	void	(Harl::*_complain[NB_LEVELS])( void );
};

enum e_complain {

	e_DEBUG,
	e_INFO,
	e_WARNING,
	e_ERROR
};

#endif
