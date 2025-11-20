
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class Bureaucrat;

class  RobotomyRequestForm : public AForm {

private: 

	const std::string _target;
	
public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm(void);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm & copy);

	void	execute(Bureaucrat const & executor) const;

	class RobotomyFailException : public std::exception
	{
		public:
		virtual const char* what(void) const throw();
	};
};

#endif
