/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:42:01 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/16 20:16:21 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	my_upper(std::string& s) {

	for (std::string::iterator it = s.begin(); it != s.end(); it++) {
		if (std::islower(*it))
			*it = std::toupper(*it);}
}

int main(int ac, char **ags) {

	if (ac < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);}

	int i = 1;
	while (i < ac) {
		std::string s(ags[i++]);
		my_upper(s);
		std::cout << s;}
	std::cout << std::endl;
	return (0);
}
