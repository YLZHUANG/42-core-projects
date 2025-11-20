/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:44:05 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/31 21:44:40 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap(void); 
	FragTrap(std::string name);
	FragTrap(FragTrap const & rhs);
	~FragTrap(void);

	FragTrap& operator=(FragTrap const &other);
	void attack(const std::string& target);
	void highFivesGuys(void);
};

#endif
