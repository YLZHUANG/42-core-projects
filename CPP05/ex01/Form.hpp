/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:18:05 by yzhuang           #+#    #+#             */
/*   Updated: 2024/11/27 12:54:27 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class  Form {

private:

	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_exe_grade;
	
public:

	Form(void);
	Form(std::string name, int sgrade, int egrade);
	Form(const Form &copy);
	~Form(void);
	Form				&operator=(const Form & copy);

	const std::string	&getName(void) const;
	int 				getStatus(void) const;
	const int 			&getSgrade(void) const;
	const int 			&getEgrade(void) const;
	void				beSigned(Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Form const &f);

#endif
