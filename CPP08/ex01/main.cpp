#include "Span.hpp"

int	main(void) {

		std::cout << "<<<<<<<<<< TEST 1 : given test " << std::endl;
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "<<<<<<<<<< TEST 2 : adding 11000 numbers " << std::endl;
		try
		{
			Span sp2(11000);
			for (int i = 0; i != 11000; i++)
				sp2.addNumber(i);
			std::cout << "Longest span  : " << sp2.longestSpan() << std::endl;
			std::cout << "Shortest span : " << sp2.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "<<<<<<<<<< TEST 3 : adding 15 numbers to a 10 span " << std::endl;
		try
		{
			Span sp3(10);
			for (int i = 0; i < 15; i++)
				sp3.addNumber(i);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "<<<<<<<<<< TEST 4 : adding range 0 - 19 after number 28" << std::endl;
		try
		{
			Span sp4(100);
			sp4.addNumber(28);


			std::vector<int> range;
			for (size_t i = 0; i < 20; i++)
				range.push_back(i);

			sp4.addRange(range.begin(), range.end());

			std::cout << "Longest span  : " << sp4.longestSpan() << std::endl;
			std::cout << "Shortest span : " << sp4.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	return (0);
}