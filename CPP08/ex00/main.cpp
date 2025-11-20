#include "easyfind.hpp"

int	main(void) {

	std::vector<int> container1;
	std::list<int> container2;

	for (int i = 0; i < 3; i++)
		container1.push_back(i);

	
	for (int i = -3; i < 2; i++)
		container2.push_back(i);

	try
	{
		std::vector<int>::iterator res1 = easyfind(container1, 2);
		std::cout << "Found :" << *res1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::list<int>::iterator res2 = easyfind(container2, 2);
		std::cout
			<< "Found :" << *res2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}