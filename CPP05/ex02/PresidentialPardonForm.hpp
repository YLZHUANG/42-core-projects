
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class  PresidentialPardonForm : public AForm {

private: 

	const std::string _target;
	
public:

	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string  target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm(void);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm & copy);

	void	execute(Bureaucrat const & executor) const;
};

#endif
