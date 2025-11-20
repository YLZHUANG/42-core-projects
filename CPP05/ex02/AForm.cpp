/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:27:58 by yzhuang           #+#    #+#             */
/*   Updated: 2024/11/27 15:38:05 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("AF"), _signed(false), _sign_grade(1), _exe_grade(1) {}

AForm::AForm(std::string name, int sgrade, int egrade) : _name(name), _signed(false), _sign_grade(sgrade), _exe_grade(egrade)
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

AForm &AForm::operator=(const AForm &other)
{
	(std::string)this->_name = other._name;
	this->_signed = other._signed;
	(int &)this->_sign_grade = other._sign_grade;
	(int &)this->_exe_grade = other._exe_grade;
	return (*this);
}

AForm::AForm(const AForm &copy)
	: _name(copy._name), _signed(copy._signed), _sign_grade(copy._sign_grade), _exe_grade(copy._exe_grade) {}

AForm::~AForm(void) {}

const std::string &AForm::getName(void) const
{
	return (this->_name);
}

int AForm::getStatus(void) const
{
	return (this->_signed);
}

const int &AForm::getSgrade(void) const
{
	return (this->_sign_grade);
}

const int &AForm::getEgrade(void) const
{
	return (this->_exe_grade);
}

void	AForm::beSigned(Bureaucrat &b)
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

void	AForm::beExecuted(Bureaucrat const &b) const
{
	try
	{
		if (this->_signed == false)
			throw FormNotSignedException();
		else if (b.getGrade() <= this->_exe_grade)
			this->execute(b);
		else
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

const char* AForm::GradeTooHighException::what(void) const throw() {

	return ("Sorry, grade too high or no sens."); }


const char* AForm::GradeTooLowException::what(void) const throw() {
	
	return ("Sorry, grade too low."); }


const char* AForm::FormNotSignedException::what(void) const throw() {
	
	return ("Sorry, form is not signed, can not be executed."); }

std::ostream &operator<<(std::ostream &os, AForm const &f)
{
	if (f.getSgrade() <= 150 && f.getSgrade() >= 1 && f.getEgrade() <= 150 && f.getEgrade() >= 1)
	{
		os << f.getName();
		if (f.getStatus())
			os << " is signed, ";
		else
			os << " is not signed, grade ";
		os << f.getSgrade() << " is required to sign it, grade " << f.getEgrade() << " is required to execute it." << std::endl;

	}
	return (os);
}
