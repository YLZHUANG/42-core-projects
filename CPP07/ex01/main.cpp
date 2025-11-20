/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:02:33 by yzhuang           #+#    #+#             */
/*   Updated: 2024/12/09 13:02:35 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	print_i(const int &i)
{
	std::cout << "<<<< printing" << std::endl;
	std::cout << i << std::endl;
}

int	main( void ) {

	int array[] = {1, 3, 5, 7};
	size_t len = 4;

	iter(array, len, print_i);

return 0; }