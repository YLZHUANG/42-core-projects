/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:29:37 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 15:58:39 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {

	std::string str = "HI THIS IS BRAIN";
	std::string msg = "The memory address "; 
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout << msg << "of the string variable : " << &str << std::endl;
	std::cout << msg << "held by stringPTR      : " << &stringPTR << std::endl;
	std::cout << msg << "held by stringREF      : " << &stringREF << std::endl;

	std::cout << "The value of the string variable          : " << str << std::endl;
	std::cout << "The value pointed to by stringPTR         : " << stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF         : " << stringREF << std::endl;
	
	return (0);
}