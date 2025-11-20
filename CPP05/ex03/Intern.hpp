
#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class  AForm;
class  Intern {

public:

	Intern(void);
	Intern(const Intern &copy);
	~Intern(void);
	
	Intern	&operator=(const Intern & other);
	AForm *makeForm(std::string name, std::string target);

	class UnvalidFormException : public std::exception
	{
		public:
		virtual const char* what(void) const throw();
	};
};

#endif
