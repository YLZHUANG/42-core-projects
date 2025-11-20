/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:25:04 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/16 20:41:48 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# define INFO_SIZE 5

class Contact {

public:

		std::string titles[INFO_SIZE];

		Contact( void );
		~Contact( void );
	
		void	setter(std::string info, int i_info);
		std::string	getter( int info_id ) const ;

private:
		std::string	_info[INFO_SIZE];
};

#endif
