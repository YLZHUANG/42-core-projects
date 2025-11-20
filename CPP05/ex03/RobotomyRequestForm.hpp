
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include "AForm.hpp"

class Bureaucrat;
class  RobotomyRequestForm : public AForm {

private: 

	const std::string _target;
	
public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string  target);
	RobotomyRequestForm(std::string const name, std::string const target);
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
