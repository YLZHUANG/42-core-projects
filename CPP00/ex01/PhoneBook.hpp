/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:04:23 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 12:33:54 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdio>
# include "Contact.hpp"
# define BOOK_SIZE 8

class PhoneBook {

public:

	bool	open;

	PhoneBook( void );
	~PhoneBook( void );
	void	do_menu( void ) const;
	void	do_add( void );
	void	do_search( void );
	void	do_exit( void );

private:

	Contact	_contacts[BOOK_SIZE];
	int		_count_contacts;
	int		_i_contact;

	std::string	_get_info(std::string msg);
	void		_print_sum( void );
	void		_print_select( void );
	void		_do_clear( void ) const;
};

#endif
