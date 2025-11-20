/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:25:35 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/16 20:39:00 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main() {

	PhoneBook   book;
	std::string command;

	book.do_menu();
	while (book.open)
	{
		std::cout << "\U000025FC Enter your command \U000025B6 " << std::endl;
		if (std::getline(std::cin, command))
		{
			if (command == "ADD")
				book.do_add();
			else if (command == "SEARCH")
				book.do_search();
			else if (command == "EXIT")
				book.do_exit();
			else
				std::cout << "\U0000203C Command not found. " << std::endl;
		} 
		else 
		{
			std::cin.clear();
			clearerr(stdin);
			continue;
		}
		command.clear();
	} 
	return 0;
}
