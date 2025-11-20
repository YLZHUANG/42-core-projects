/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:39:03 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 22:08:32 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP
# include <iostream>
# include <climits>

class ClapTrap {

public:

	ClapTrap(void);
	ClapTrap(ClapTrap const & rhs);
	ClapTrap(std::string name);	
	~ClapTrap(void);

	ClapTrap& operator=(ClapTrap const &other);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:

	std::string		_name;
	unsigned int	_hit_pts;
	unsigned int	_energy_pts;
	unsigned int	_attack_dmg;
};

#endif

