/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:36:28 by yzhuang           #+#    #+#             */
/*   Updated: 2024/11/27 13:36:30 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("B"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	try
	{
		if (this->_grade < 1)
			throw GradeTooHighException();
		else if (this->_grade > 150)
			throw GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{

	this->_grade = other._grade;
	return (*this);
}

const std::string &Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

Bureaucrat &Bureaucrat::operator++(void)
{
	try
	{
		if (this->_grade == 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (*this);
}

Bureaucrat &Bureaucrat::operator--(void) 
{
	try
	{
		if (this->_grade == 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (*this);
}

void Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

void	Bureaucrat::signForm(AForm &form)
{
	if (form.getStatus() == true)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName();
		std::cout << ", because it is already signed." << std::endl;
		return;
	}
	form.beSigned(*this);
	if (form.getStatus() == true)
		std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
	else
		{
			std::cout << this->getName() << " couldn't sign " << form.getName();
			std::cout << ", because grade too low." << std::endl;
		}
	return;
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	form.beExecuted(*this);
	return;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {

	return ("Sorry, grade too high or no sens."); }


const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	
	return ("Sorry, grade too low."); }

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	if (b.getGrade() <= 150 && b.getGrade() >= 1)
		os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}
