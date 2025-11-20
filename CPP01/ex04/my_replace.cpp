/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_replace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:11:55 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:12:21 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_replace.hpp"

void	my_validation(std::ifstream& f1, std::ofstream& f2, std::string s) {

	if (!f1.good() || !f2.good()) {
		f1.close();
		f2.close();
		std::cerr << "I/O open error" << std::endl;
		exit(EXIT_FAILURE); }

	if (!f1) {
		f1.close();
		f2.close();
		exit(EXIT_SUCCESS); }

	if (s.empty()) {
		f2 << f1.rdbuf();
		f1.close();
		f2.close();
		exit(EXIT_SUCCESS); }
}

void	my_replace(std::string filename, std::string s1, std::string s2) {

	std::ifstream f1;
	std::ofstream f2;
	std::size_t p;
	std::size_t start;

	p = 0;
	start = 0;
	f1.open(filename.c_str());
	if (f1.good())
		f2.open((filename + ".replace").c_str());
	my_validation(f1, f2, s1);
	std::string content = std::string(std::istreambuf_iterator<char>(f1), std::istreambuf_iterator<char>());
	do {
		p = content.find(s1, start);
		if (p != std::string::npos ) {
			f2 << content.substr(start, p - start);
			f2 << s2;
			start = p + s1.size(); }
		else
			f2 << content.substr(start, std::string::npos);
	} while (p != std::string::npos);
	f1.close();
	f2.close();
}
