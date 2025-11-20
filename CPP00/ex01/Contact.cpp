/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:23:47 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/16 20:24:05 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	
    titles[0] = "FIRST NAME : ";
    titles[1] = "LAST NAME : ";
    titles[2] = "NICK NAME : ";
    titles[3] = "PHONE NUMBER : ";
    titles[4] = "DARKEST SECRET : ";
}

Contact::~Contact( void ) {
};

void	Contact::setter( std::string info, int i_info ) {

	this->_info[i_info] = info;
};

std::string	Contact::getter( int info_id ) const {

	return this->_info[info_id];
};
