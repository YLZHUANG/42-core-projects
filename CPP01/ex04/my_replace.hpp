/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_replace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:12:32 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:12:40 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_REPLACE_HPP
# define MY_REPLACE_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

void	my_validation(std::ifstream& f1, std::ofstream& f2, std::string s);
void	my_replace(std::string filename, std::string s1, std::string s2);

#endif
