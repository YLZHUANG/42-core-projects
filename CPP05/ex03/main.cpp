#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "<<<<<<<<<<<<<<<<<<<<<< TEST 1 >>>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << "<<<< Creating bureaucrat b" << std::endl;
	Bureaucrat b("b", 1);
	std::cout << b << std::endl;

	std::cout << "<<<<< Random intern makes form" << std::endl;
	Intern  someRandomIntern;
	AForm*   rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	if (rrf)
	{
		std::cout << *rrf << std::endl;
		std::cout << "<<<< Bureaucrat b is signing form" << std::endl;
		b.signForm(*rrf);
		std::cout << "<<<< Bureaucrat b is executing form" << std::endl;
		b.executeForm(*rrf);
		delete rrf;
	}	

	std::cout << "\n<<<<<<<<<<<<<<<<<<<<<< TEST 2 >>>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << "<<<< Creating bureaucrat b2" << std::endl;
	Bureaucrat b2("b2", 1);
	std::cout << b2 << std::endl;

	Intern  someRandomIntern2;
	AForm*   rrf2;

	std::cout << "<<<<< Random intern makes form" << std::endl;
	rrf2 = someRandomIntern2.makeForm("noexist request", "Bender");

	if (rrf2)
	{
		std::cout << "<<<< Bureaucrat b2 is signing form" << std::endl;
		b2.signForm(*rrf2);
		std::cout << "<<<< Bureaucrat b2 is executing form" << std::endl;
		b2.executeForm(*rrf2);
		delete rrf2;
	}	

	return (0);
}
