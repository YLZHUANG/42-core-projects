/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:12:48 by yzhuang           #+#    #+#             */
/*   Updated: 2024/01/29 16:22:14 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int main(void) {

	std::ofstream file1;
	file1.open("file1");
	if (file1.good()) 
		file1 << "hello, how are you? hello? hello, I'm fine, and you?";
	else
		std::cerr << "file1 open error" << std::endl;
	file1.close();

	std::ofstream file2;
	file2.open("file2");
	if (!file2.good()) 
		std::cerr << "file2 open error" << std::endl;
	file2.close();
	std::cout << "STARTING ======== \nfile1 and file 2 created for tests \n" << std::endl;

	std::cout << "TEST 1 : Source: file1, S1: hello, S2: bonjour" << std::endl;
	std::cout << "EXECUTING =============" << std::endl;
	my_replace("file1", "hello", "bonjour");
	std::cout << "file1: hello, how are you? hello? hello, I'm fine, and you?" << std::endl;
	std::ifstream replaced_content;
	replaced_content.open("file1.replace");
	if (replaced_content.good()) {
		std::string content = std::string(std::istreambuf_iterator<char>(replaced_content), std::istreambuf_iterator<char>());
		std::cout << "file1.replace: " << content << std::endl; }
	replaced_content.close();
	std::cout << std::endl;

	std::cout << "TEST 2 : Source: file1, S1: hello, S2: (empty)" << std::endl;
	std::cout << "EXECUTING =============" << std::endl;
	my_replace("file1", "hello, ", "");
	std::cout << "file1: hello, how are you? hello? hello, I'm fine, and you?" << std::endl;
	std::ifstream replaced_content2;
	replaced_content2.open("file1.replace");
	if (replaced_content2.good()) {
		std::string content2 = std::string(std::istreambuf_iterator<char>(replaced_content2), std::istreambuf_iterator<char>());
		std::cout << "file1.replace: " << content2 << std::endl; }
	replaced_content2.close();
	std::cout << std::endl;

	std::cout << "TEST 3 : Source: file2 (empty), S1: hello, S2: bonjour" << std::endl;
	std::cout << "EXECUTING =============" << std::endl;
	my_replace("file2", "hello", "bonjour");
	std::cout << "file2: (empty)" << std::endl;
	std::ifstream replaced_content3;
	replaced_content3.open("file2.replace");
	if (replaced_content3.good()) {
		std::string content3 = std::string(std::istreambuf_iterator<char>(replaced_content3), std::istreambuf_iterator<char>());
		std::cout << "file2.replace: (empty)" << content3 << std::endl;}
	replaced_content3.close();
	std::cout << std::endl;

	std::cout << "TEST 4 : Source: file3 (non-exist), S1: hello, S2: bonjour" << std::endl;
	std::cout << "File3 is non-exist, so you will see an I/O open error message and no file3.replace created." << std::endl;
	std::cout << "EXECUTING =============" << std::endl;
	my_replace("file3", "hello", "bonjour");
	std::cout << std::endl;

	return (0); }