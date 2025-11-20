#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(const Span &copy) : _N(copy._N), _numbers(copy._numbers){}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_N = other._N;
		_numbers = other._numbers;
	};
	return (*this);
}

void	Span::addNumber(int num) {

	if (_numbers.size() == _N) {
		throw (std::runtime_error("Can not add more number. Span is full."));
	}
	_numbers.push_back(num);
}

int		Span::shortestSpan() {

	if (_numbers.size() < 2) {
		throw (std::runtime_error("Not enough numbers to find the shortest span."));
	}
	int res = std::numeric_limits<int>::max();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	for (unsigned i = 1; i < sorted.size(); i++) {
		int nres = sorted[i] - sorted[i - 1];
		if ( nres < res)
			res = nres;
	};
	return (res);
}

int		Span::longestSpan() {

	if (_numbers.size() < 2) {
		throw (std::runtime_error("Not enough numbers to find the longest span."));
	}
	return (*(std::max_element(_numbers.begin(), _numbers.end())) - *(std::min_element(_numbers.begin(), _numbers.end())));
}
