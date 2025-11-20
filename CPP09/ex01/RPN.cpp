#include "RPN.hpp"

Rpn::Rpn() {}

Rpn::Rpn(std::string expression) : _expression(expression) {

	validateExpression();
}

Rpn::~Rpn() {}

Rpn::Rpn(const Rpn &copy) : _expression(copy._expression) {}

Rpn &Rpn::operator=(const Rpn &other) {
	if (this != &other) {
		_expression = other._expression;
	};
	return (*this);
}

void		Rpn::validateExpression( void ) {

	if (_expression.empty() || _expression.find_first_not_of(VALID_EXP) != std::string::npos)
		throw (std::runtime_error("Error"));
}

double	Rpn::op(double first, double second, char op) {

	switch (op)
	{
		case ('+'):
			return (first + second);
		case ('-'):
			return (first - second);
		case ('*'):
			return (first * second);
		case ('/'):
			if (!second)
				throw (std::runtime_error("Error: op : division by zero"));
			return (first / second);
	default:
		throw (std::runtime_error("Error: op : operator"));
	}
}

double	Rpn::calculator( void ) {


	std::istringstream tokens(_expression);
	std::string	token;
	std::stack<double> stack;
	double	res = 0;

	while (tokens >> token) {
	
		if (token.size() != 1)
			throw (std::runtime_error("Error"));

		if (isdigit(token[0]))
			stack.push(token[0] - '0');
		else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {

			if (stack.size() < 2)
				throw (std::runtime_error("Error"));
			double	second = stack.top(); stack.pop();
			double	first = stack.top(); stack.pop();
			res = op(first, second, token[0]);
			stack.push(res);
		}		
	}
	if (stack.size() != 1)
		throw (std::runtime_error("Error"));
	return (stack.top());
}

