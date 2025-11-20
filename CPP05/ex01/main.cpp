/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:17:54 by yzhuang           #+#    #+#             */
/*   Updated: 2024/11/27 12:58:52 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

int	main(void)
{
	std::cout << "Try to initiate Bureaucrat a >>>>>" << std::endl;
	Bureaucrat a("a", 149);
	std::cout << "Printing info >>" << std::endl;
	std::cout << a << std::endl;

	std::cout << "Try to initiate Form Agreement >>>>>" << std::endl;
	Form f("Agreement", 4, 5);
	std::cout << "Printing info >>" << std::endl;
	std::cout << f << std::endl;

	a.setGrade(100);
	std::cout << "a of grade 100 try to sign a document 'Agreement' >>>>>" << std::endl;
	a.signForm(f);

	a.setGrade(1);
	std::cout << "\na of grade 1 try to sign a document 'Agreement' >>>>>" << std::endl;
	a.signForm(f);

	std::cout << "\na try to sign the 'Agreement' that is already signed >>>>>" << std::endl;
	a.signForm(f);
	return (0);
}
