#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<< Forms initiation >>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;

	std::cout << "Try to initiate a ShrubberyCreationForm sf >>>>>" << std::endl;
	ShrubberyCreationForm sf("sf");
	std::cout << sf << std::endl;
	std::cout << "Try to initiate a RobotomyRequestForm rf>>>>>" << std::endl;
	RobotomyRequestForm rf("rf");
	std::cout << rf << std::endl;
	std::cout << "Try to initiate a PresidentialPardonForm pf >>>>>" << std::endl;
	PresidentialPardonForm pf("pf");
	std::cout << pf << std::endl;

	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< Test Bureaucrat b (all allowed) >>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << "Try to initiate Bureaucrat b >>>>>" << std::endl;
	Bureaucrat b("b", 1);
	std::cout << b << std::endl;
	std::cout << "sign sf >>" << std::endl;
	b.signForm(sf);
	std::cout << "execute sf >>" << std::endl;
	b.executeForm(sf);
	std::cout << "sign rf >>" << std::endl;
	b.signForm(rf);
	std::cout << "execute rf >>" << std::endl;
	b.executeForm(rf);
	std::cout << "execute rf again >>" << std::endl;
	b.executeForm(rf);
	std::cout << "execute rf again >>" << std::endl;
	b.executeForm(rf);
	std::cout << "sign pf >>" << std::endl;
	b.signForm(pf);
	std::cout << "execute pf >>" << std::endl;
	b.executeForm(pf);
	std::cout << std::endl;

	std::cout << "<<<<<<<<<<<<<<<<<<< Test Bureaucrat b1 (already signed) >>>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << "Try to initiate Bureaucrat b1 >>>>>" << std::endl;
	Bureaucrat b1("b1", 140);
	std::cout << b1 << std::endl;
	std::cout << "sign sf >>" << std::endl;
	b1.signForm(sf);
	std::cout << "execute sf >>" << std::endl;
	b1.executeForm(sf);
	std::cout << std::endl;
	std::cout << "sign rf >>" << std::endl;
	b1.signForm(rf);
	std::cout << "execute rf >>" << std::endl;
	b1.executeForm(rf);
	std::cout << std::endl;
	std::cout << "sign pf >>" << std::endl;
	b1.signForm(pf);
	std::cout << "execute pf >>" << std::endl;
	b1.executeForm(pf);
	std::cout << std::endl;

	std::cout << "<<<<<<<<< Test Bureaucrat b1 with new forms (partially allowed) >>>>>>" << std::endl;	
	std::cout << "Try to initiate a ShrubberyCreationForm sf >>>>>" << std::endl;
	ShrubberyCreationForm sf2("sf2");
	std::cout << sf2 << std::endl;
	std::cout << "Try to initiate a RobotomyRequestForm rf2 >>>>>" << std::endl;
	RobotomyRequestForm rf2("rf2");
	std::cout << rf2 << std::endl;
	std::cout << "Try to initiate a PresidentialPardonForm pf2 >>>>>" << std::endl;
	PresidentialPardonForm pf2("pf2");
	std::cout << pf2 << std::endl;

	std::cout << "sign sf2 >>" << std::endl;
	b1.signForm(sf2);
	std::cout << "execute sf2 >>" << std::endl;
	b1.executeForm(sf2);
	std::cout << std::endl;
	std::cout << "sign rf2 >>" << std::endl;
	b1.signForm(rf2);
	std::cout << "execute rf2 >>" << std::endl;
	b1.executeForm(rf2);
	std::cout << std::endl;
	std::cout << "sign pf2 >>" << std::endl;
	b1.signForm(pf2);
	std::cout << "execute pf2 >>" << std::endl;
	b1.executeForm(pf2);
	std::cout << std::endl;

	return (0);
}
