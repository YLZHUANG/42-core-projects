#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &copy)
{
	*this = copy;
	return;
}

Intern::~Intern(void) {}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other) {}
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = { "shrubbery request", 
							"robotomy request",
							"presidentialpardon request" };
	AForm *res = NULL;

	try
	{
		int i_names = -1;
		for (int i = 0; i < 3; i++) {
			if (names[i] == name)
				i_names = i; }
	
		switch (i_names) {
			case (-1) : {
				throw UnvalidFormException();
				break; }
			case (0) : {
				res = new ShrubberyCreationForm(name, target);
				break; }
			case (1) : {
				res = new RobotomyRequestForm(name, target); 
				break; }
			case (2) : {
				res = new PresidentialPardonForm(name, target); 
				break; }
		}
		std::cout << "Intern creates " << name << " form." << std::endl; 
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	return (res);
}

const char* Intern::UnvalidFormException::what(void) const throw() {

	return ("Sorry, form name does not exist."); }