/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:30:28 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:36:11 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **ag) {

	if (ac != 2 && ac != 1)
		std::cerr << "Wrong arguments. <Option> DEBUG, INFO, WARNING, ERROR" << std::endl;
	else if (ac == 2)
	{
		Harl tester;
		std::cout << std::endl;
		tester.complain(ag[1]);
	}
	else
	{
		Harl harl;
		std::cout << "\n** Harl complains a lot! **\n" << std::endl;
		for (int i = 0; i < 5; i++) {
			harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			harl.complain("WARNING");
			harl.complain("DEBUG");
			harl.complain("INFO"); }
	}
return 0; }
