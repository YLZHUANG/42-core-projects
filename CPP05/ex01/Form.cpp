/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:19:34 by yzhuang           #+#    #+#             */
/*   Updated: 2024/11/27 12:57:18 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("F"), _signed(false), _sign_grade(1), _exe_grade(1) {}

Form::Form(std::string name, int sgrade, int egrade) : _name(name), _signed(false), _sign_grade(sgrade), _exe_grade(egrade)
{
	try
	{
		if (this->_sign_grade < 1 || this->_exe_grade < 1)
			throw GradeTooHighException();
		else if (this->_sign_grade > 150 || this->_exe_grade > 150)
			throw GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

Form &Form::operator=(const Form &other)
{
	(std::string)this->_name = other._name;
	this->_signed = other._signed;
	(int &)this->_sign_grade = other._sign_grade;
	(int &)this->_exe_grade = other._exe_grade;
	return (*this);
}

Form::Form(const Form &copy)
	: _name(copy._name), _signed(copy._signed), _sign_grade(copy._sign_grade), _exe_grade(copy._exe_grade) {}

Form::~Form(void) {}

const std::string &Form::getName(void) const
{
	return (this->_name);
}

int Form::getStatus(void) const
{
	return (this->_signed);
}

const int &Form::getSgrade(void) const
{
	return (this->_sign_grade);
}

const int &Form::getEgrade(void) const
{
	return (this->_exe_grade);
}

void	Form::beSigned(Bureaucrat &b)
{
	try
	{
		if (b.getGrade() <= this->_sign_grade)
			this->_signed = true;	
		else
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

const char* Form::GradeTooHighException::what(void) const throw() {
	
	return ("Sorry, grade too high or no sens."); }


const char* Form::GradeTooLowException::what(void) const throw() {
	
	return ("Sorry, grade too low."); }


std::ostream &operator<<(std::ostream &os, Form const &f)
{
	if (f.getSgrade() <= 150 && f.getSgrade() >= 1 && f.getEgrade() <= 150 && f.getEgrade() >= 1)
	{
		os << f.getName();
		os << (f.getStatus()? ", is signed." : " is not signed.") << std::endl;
		os << "Grade " << f.getSgrade() << " is required to sign it; Grade " << f.getEgrade() << " is required to execute it." << std::endl;
	}
	return (os);
}
