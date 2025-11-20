/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:47:38 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:47:40 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **ag) {

	if (ac != 2) {
		std::cerr << "This programm requires 1 argument. <Option> DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1); }

	Harl harl;
	harl.filter(ag[1]);
	return (0);
}
