/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:13:08 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:13:13 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP
# include <iostream>
# include <fstream>
# include <string>

void	my_validation(std::ifstream& f1, std::ofstream& f2, std::string s);
void	my_replace(std::string filename, std::string s1, std::string s2);

#endif
