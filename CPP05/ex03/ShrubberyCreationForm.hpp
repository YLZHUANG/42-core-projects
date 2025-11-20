
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class Bureaucrat;

class  ShrubberyCreationForm : public AForm {

private: 
	const std::string _target;
	
public:

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(std::string const name, std::string const target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm & copy);

	void	execute(Bureaucrat const & executor) const;

	class FileOpenFailException : public std::exception
	{
		public:
		virtual const char* what(void) const throw();
	};
};

#endif
