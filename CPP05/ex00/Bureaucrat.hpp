/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:09:42 by yzhuang           #+#    #+#             */
/*   Updated: 2024/11/27 15:53:08 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
class  Bureaucrat {
	
private:

	const std::string	_name;
	int					_grade;

public:

	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat(void);
	
	Bureaucrat	&operator=(const Bureaucrat & other);
	Bureaucrat	&operator++(void);
	Bureaucrat	&operator--(void);

	const std::string	&getName(void) const;
	int					getGrade(void) const;
	void				setGrade(int grade);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b);

#endif
