/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:07:51 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:34:43 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_replace.hpp"

int main(int ac, char **ag) {

	if (ac < 4)
	{
		std::cout << "The program requires 3 arguments : 1 file, 2 strings." << std::endl;
		return (0);
	}
	my_replace(ag[1], ag[2], ag[3]);

return 0; }