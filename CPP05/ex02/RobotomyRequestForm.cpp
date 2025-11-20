#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) 
	: AForm("RobotomyRequestForm", 72, 45) {
	srand(time(NULL));}
	
RobotomyRequestForm::RobotomyRequestForm(std::string const target) 
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
	srand(time(NULL));}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
	: AForm(copy), _target(copy._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (&other != this)
	{
		AForm::operator=(other);
		(std::string)this->_target = other._target;
	}	
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	(void) executor;
	std::cout << "DDDD~~~~~~~DDDDDD~~~~~~~DDDDD~~~~~~~" << std::endl;
	try 
	{
		if (rand() % 2)
			std::cout << this->_target << " has been robotomized successfully." << std::endl;
		else
			throw RobotomyRequestForm::RobotomyFailException();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

const char*RobotomyRequestForm::RobotomyFailException::what(void) const throw() {
	
	return ("Robotomy failed.");}
