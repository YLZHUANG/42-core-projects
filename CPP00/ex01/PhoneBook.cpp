/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:39:14 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 12:38:22 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : open(true), _count_contacts(0), _i_contact(0) {
};

PhoneBook::~PhoneBook( void ) {
};

void	PhoneBook::do_menu( void ) const {
	
	std::cout << "\U0000260E  Welcome! The book is empty. <Options : ADD, SEARCH, or EXIT>" << std::endl;
}

void	PhoneBook::do_add( void ) {

		Contact	new_contact;
		std::string	t;
		int	i;

		for (i = 0; i < INFO_SIZE; i++)
		{
			t = this->_get_info(new_contact.titles[i]);
			if (t == "^D")
			{
				open = false;
				t.clear();
				return;
			}	
			new_contact.setter(t, i);
			t.clear();
		}
		std::cout << "\U00002714 Congratulations! The contact is saved. " << std::endl;
		this->_contacts[_i_contact] = new_contact;
		this->_i_contact++;
		this->_count_contacts++;
		if (this->_i_contact == 8)
			this->_i_contact = 0;
		if (this->_count_contacts > 8)
			this->_count_contacts = 8;
}

void	PhoneBook::do_search( void ) {

	if (!this->_count_contacts)
	{
		std::cout << "\U00002139 The Phonebook is empty." << std::endl;
		return ;
	}	
	this->_print_sum();
	this->_print_select();
}

void	PhoneBook::do_exit( void ) {

	open = false;
	std::cout << "\U000025FC Good bye ! \U00002665" << std::endl;
	std::cout << std::setfill('*') << std::setw(60) << " " << std::endl;
}

std::string	PhoneBook::_get_info( std::string msg ) {

		std::string	info;
		bool	valid;

		valid = false;
		std::cout << msg;
		do{
			
			std::getline(std::cin, info);
			if (std::cin.eof())
			{
				info = "^D";
				valid = true;
			}
			else if (info.empty())
				std::cout << "\U00002716 Entry can not be empty.\n" << msg;
			else
				valid = true;
			_do_clear();
		} while (valid == false);
		return info;
}

void	PhoneBook::_print_sum( void ) {

	int	i;
	int	j;
	
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (i = 0; i < this->_count_contacts; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		for (j = 0; j < 3; j++)
		{
				if (this->_contacts[i].getter(j).length() > 10)
					std::cout << std::setw(9) << this->_contacts[i].getter(j).substr(0, 9) << ".|";
				else
					std::cout << std::setw(10) << this->_contacts[i].getter(j) << "|";
		}
		std::cout << "\n";
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void	PhoneBook::_print_select( void ) {

	int	select;
	int	i;
	bool valid = false;

	std::cout << "\U000025FC Enter the contact index \U000025B6 ";
	do {
		std::cin >> select;
		if (std::cin.eof())
		{
			std::cout << " " << std::endl;
			this->_do_clear();
			return ;
		}
		else if (!std::cin.fail())
		{
			if (select < 0 || select > 7)
				std::cout << "\U00002716 Out of range. Enter a number between 0 and 7 \U000025B6 ";
			else if (select >= this->_count_contacts)
				std::cout << "\U00002716 Contact not exist. Enter an existing contact index \U000025B6 ";
			else
				valid = true;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			this->_do_clear();
		}
		else
		{
			std::cout << "\U00002716 Wrong entry. Enter an integer between 0 and 7 \U000025B6 ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   
		}
	} while (valid == false);

	std::cout << "****************" << std::endl;
	std::cout << "\U00002714 " << "Contact No." << select << std::endl;
	for (i = 0; i < INFO_SIZE; i++)
		std::cout << this->_contacts[select].titles[i] << this->_contacts[select].getter(i) << std::endl;
	std::cout << "****************" << std::endl;
}

void	PhoneBook::_do_clear( void ) const {

	std::cin.clear();
	clearerr(stdin);
	std::cin.sync();
}
