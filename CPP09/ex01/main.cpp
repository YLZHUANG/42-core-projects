#include "RPN.hpp"

int	main(int ac, char **av) {

	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	try {

		Rpn r(av[1]);
		std::cout << std::fixed << std::setprecision(0);
		std::cout << std::fixed << std::setprecision(2);
		std::cout << r.calculator() << std::endl; 
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}
