/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:50:27 by yzhuang           #+#    #+#             */
/*   Updated: 2024/02/01 15:50:28 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_HPP
# define Brain_HPP
# include <iostream>
# include <cstdlib>

class Brain {

public:

	Brain( void );
	Brain( Brain const & rhs );
	~Brain( void );

	Brain& operator=(Brain const & other);
	const std::string& getIdea( void ) const;

protected:

	std::string ideas[100];
};

#endif
