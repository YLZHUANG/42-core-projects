/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:53:27 by yzhuang           #+#    #+#             */
/*   Updated: 2024/11/27 14:21:34 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class  AForm {

private:

	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_exe_grade;
	
public:

	AForm(void);
	AForm(std::string name, int sgrade, int egrade);
	AForm(const AForm &copy);
	virtual ~AForm(void);
	virtual AForm	&operator=(const AForm & copy);

	virtual const std::string	&getName(void) const;
	virtual int 				getStatus(void) const;
	virtual const int 			&getSgrade(void) const;
	virtual const int 			&getEgrade(void) const;
	virtual void				beSigned(Bureaucrat &b);
	virtual void				beExecuted(Bureaucrat const &b) const;
	virtual void				execute(Bureaucrat const & executor) const = 0;

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
	
	class FormNotSignedException: public std::exception
	{
		public:
		virtual const char* what(void) const throw();
	};

};

std::ostream &operator<<(std::ostream &os, AForm const &f);

#endif
