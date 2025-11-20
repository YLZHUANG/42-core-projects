/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:20:20 by yzhuang           #+#    #+#             */
/*   Updated: 2024/12/09 11:38:24 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {

	try
	{
		unsigned int	ui = 499999;
		
		Data *p = new Data(ui);
		uintptr_t raw = Serializer::serialize(p);
		Data *ptr = Serializer::deserialize(raw);

		if (p == ptr)
		{
			std::cout << "SUCCES!" << std::endl;
			std::cout << "The data in the deserialized pointer is " <<  ptr->data <<  "." << std::endl;
		}
		else
			std::cout << "SOMETHING WRONG!" << std::endl;
		delete ptr;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
