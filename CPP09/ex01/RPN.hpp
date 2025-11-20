#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <iomanip>

# define VALID_EXP "0123456789+-*/ \t"

class Rpn {

public: 

	Rpn( void );
	Rpn(std::string expression);
	~Rpn( void );
	Rpn(const Rpn &copy);
	Rpn &operator=(const Rpn &other);

	double	calculator( void );

private:

	std::string	_expression;
	double		op(double first, double second, char op);
	void		validateExpression( void );
};

#endif
