#include "PmergeMe.hpp"


int	main(int ac, char **av) {

	if (ac < 2)
	{
		std::cerr << "Error : need 1 argument." << std::endl;
		return (1);
	}

	try {

		PmergeMe r;
		r.parseAndLoad(ac, av);
		r.doPmergeMe(); 
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}
