#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {

	std::string line;

	if (ac != 2)
	{
		std::cout << "Wrong arguments: need a input file to evaluate" << std::endl;
		return (1);
	}

	try {
		std::ifstream input(av[1]);
		if (!input.is_open())
			throw std::runtime_error("Can not open input file");

		BitcoinExchange b("data.csv");
		getline(input, line);
		while (getline(input, line)) {
			if (line.empty()) {
				std::cout << std::endl;
				continue ;
			}

			if (b.bitcoinExchange(line) == 0)
				std::cout << b << std::endl;
		}
		input.close();
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}