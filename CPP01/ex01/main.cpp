/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:14:45 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 13:27:53 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	
	int	nb = 5;

	Zombie	*horde = zombieHorde(nb, "Zombie");
	if (!horde)
		return (0);
	std::cout << "*** First horde ***" << std::endl;
	for (int i = 0; i < nb; i++)
		horde[i].announce();
	delete [] horde;

	nb = 1;
	Zombie *horde2 = zombieHorde(nb, "Single Zombie");
	if (!horde2)
		return (0);
	std::cout << "*** More ***" << std::endl;
	horde2[0].announce();
	delete [] horde2;
	return (0);
}
