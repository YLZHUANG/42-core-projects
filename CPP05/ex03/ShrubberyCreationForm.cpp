#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) 
	: AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) 
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const name, std::string const target) 
	: AForm(name, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
	: AForm(copy), _target(copy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (&other != this)
	{
		AForm::operator=(other);
		(std::string)this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream fout;

	try 
	{
		fout.open((this->_target +  "_shrubbery").c_str());
		if (fout.is_open())	
		{
			fout << "     888888888888       " << std::endl;
			fout << " 888888888888888888     " << std::endl;
			fout << "    88888888888888      " << std::endl;
			fout << "      \\\\//////        " << std::endl;
			fout << "        \\////          " << std::endl;
			fout << "        |||||           " << std::endl;
			fout << "  ......||||||........  " << std::endl;
			fout.close();
			std::cout << executor.getName() << " executed " << this->getName() << "." << std::endl;	
		}
		else
			throw ShrubberyCreationForm::FileOpenFailException();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

const char* ShrubberyCreationForm::FileOpenFailException::what(void) const throw() {
	
	return ("File open failed.");}
