/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:05:43 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 23:11:48 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public virtual ClapTrap, public ScavTrap , public FragTrap {

public:

	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const & rhs);
	~DiamondTrap(void);
	DiamondTrap& operator=(DiamondTrap const &other);

	using	ScavTrap::attack;
	void	whoAmI(void);
	void	get_state(void);

private:

	std::string		_name;
};

#endif
