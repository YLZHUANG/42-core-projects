/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:29:15 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:50:14 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {

	_complain[e_DEBUG] = &Harl::debug;
	_complain[e_INFO] = &Harl::info;
	_complain[e_WARNING] = &Harl::warning;
	_complain[e_ERROR] = &Harl::error;
}

Harl::~Harl(void) {
}

void	Harl::complain( std::string level ) {

	const std::string	msg[] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"};
	
	for (int i = 0; i < NB_LEVELS; i++) {
		if (msg[i] == level)
			(this->*_complain[i])();
	}
}

void Harl::debug( void ) {

	std::cout << "[ DEBUG ] \nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!\n" << std::endl;
}

void Harl::info( void ) {

	std::cout << "[ INFO ] \nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!" << std::endl; 
	std::cout << "If you did, I wouldn’t be asking for more!\n" << std::endl;
}


void Harl::warning( void ) {

	std::cout << "[ WARNING ] \nI think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error( void ) {

	std::cout << "[ ERROR ] \nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}
