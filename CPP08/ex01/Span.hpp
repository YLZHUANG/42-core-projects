#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <limits>

class Span {

public: 

	Span();
	Span(unsigned int N);
	~Span();
	Span(const Span &copy);
	Span &operator=(const Span &other);

	void	addNumber(int num);
	int		shortestSpan();
	int		longestSpan();

	template <typename InputIterator>
	void	addRange(InputIterator begin, InputIterator end){
	size_t size = std::distance(begin, end);
	if (size + _numbers.size() > _N)
		throw (std::runtime_error("Can not add so many numbers."));
		
	_numbers.insert(_numbers.end(), begin, end);};

private:

	unsigned int		_N;
	std::vector<int>	_numbers;
};

#endif
