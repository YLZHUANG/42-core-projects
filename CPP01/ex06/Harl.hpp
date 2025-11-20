/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:47:13 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:48:57 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

enum e_complain{

	e_DEBUG,
	e_INFO,
	e_WARNING,
	e_ERROR,
	e_TOTAL
};

class Harl {
	
public:

	Harl( void );
	~Harl( void );
	void	complain( std::string level );
	void	filter( std::string level );

private:

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void (Harl::*_complain[e_TOTAL])( void );
};

#endif
