#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
	: _rawDeque(copy._rawDeque), _deque(copy._deque), _rawVector(copy._rawVector), _vector(copy._vector) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {

	if (this != &other) {

		_rawDeque = other._rawDeque;
		_deque = other._deque;
		_rawVector = other._rawVector;
		_vector = other._vector;
	}
	return (*this);
}

void		PmergeMe::parseAndLoad(int ac, char **avs) {

	std::string	av;
	size_t		size = (size_t)ac;

	for (size_t i = 1; i < size ; i++) {

		av = avs[i];
		if (av.length() > 10 || av.find_first_not_of(VALID_EXP) != std::string::npos)
			throw (std::runtime_error("Error : unvalid argument."));
		unsigned long long t = strtoull(avs[i], NULL, 10);
		if (t > UINT_MAX)
			throw (std::runtime_error("Error : too big number."));
		
		std::istringstream iss(av);
		unsigned int num;
		if (!(iss >> num))
			throw (std::runtime_error("Error : can't convert number."));
		_rawDeque.push_back(num);
		_rawVector.push_back(num);
	}
	_vector = _rawVector;
	_deque = _rawDeque;
}

void	PmergeMe::dBinaryInsert(std::deque<unsigned int> &a, unsigned int b) {

	size_t left = 0; size_t right = a.size();
	while (left < right) {

		size_t mid = (right + left) / 2;
		if (b < a[mid]) 
			right = mid;
		else
			left = mid + 1;
	}
	a.insert(a.begin() + left, b);
}


void PmergeMe::dSortPairs(std::deque<unsigned int> &a, std::deque<unsigned int> &b, std::deque<unsigned int> &numbers) {
	size_t next, i;
	size_t size = numbers.size();

	for (i = 0; i + 1 < size; i += 2) {
		next = i + 1;
		if (numbers[i] > numbers[next]) {
			a.push_back(numbers[i]);
			b.push_back(numbers[next]);
		}
		else {
			a.push_back(numbers[next]);
			b.push_back(numbers[i]);
		}
	}

	if (i < size)
		b.push_back(numbers[i]);
}

void	PmergeMe::dMergeInsert(std::deque<unsigned int> &numbers) {

	if (numbers.size() <= 1)
		return ;
	
	std::deque<unsigned int> a, b;
	dSortPairs(a, b, numbers);

	dMergeInsert(a);

	for (size_t i = b.size(); i > 0; --i) {

		dBinaryInsert(a, b[i - 1]);
	}
	numbers = a;
}


void	PmergeMe::vBinaryInsert(std::vector<unsigned int> &a, unsigned int b) {

	size_t left = 0; size_t right = a.size();
	while (left < right) {

		size_t mid = (right + left) / 2;
		if (b < a[mid]) 
			right = mid;
		else
			left = mid + 1;
	}
	a.insert(a.begin() + left, b);
}


void PmergeMe::vSortPairs(std::vector<unsigned int> &a, std::vector<unsigned int> &b, std::vector<unsigned int> &numbers) {
	size_t next, i;
	size_t size = numbers.size();

	for (i = 0; i + 1 < size; i += 2) {
		next = i + 1;
		if (numbers[i] > numbers[next]) {
			a.push_back(numbers[i]);
			b.push_back(numbers[next]);
		}
		else {
			a.push_back(numbers[next]);
			b.push_back(numbers[i]);
		}
	}

	if (i < size)
		b.push_back(numbers[i]);
}

void	PmergeMe::vMergeInsert(std::vector<unsigned int> &numbers) {

	if (numbers.size() <= 1)
		return ;
	
	std::vector<unsigned int> a, b;
	vSortPairs(a, b, numbers);

	vMergeInsert(a);

	for (size_t i = b.size(); i > 0; --i) {

		vBinaryInsert(a, b[i - 1]);
	}
	numbers = a;
}


void		PmergeMe::doPmergeMe( void ) {

	clock_t start, end;

	// sort and mesure : deque
	start = clock();
	dMergeInsert(_deque);
	end = clock();
	double dequeTime = static_cast<double>( end - start ) / CLOCKS_PER_SEC * 1e6;

	// sort and mesure : vector
	start = clock();
	vMergeInsert(_vector);
	end = clock();
	double vectorTime = static_cast<double>( end - start ) / CLOCKS_PER_SEC * 1e6;

	// display
	std::cout << "Before:  ";
	for (size_t i = 0; i < _rawDeque.size(); i++)
		std::cout << " " << _rawDeque[i];

	std::cout << "\nAfter:   ";
	for (size_t i = 0; i < _deque.size(); i++)
		std::cout << " " << _deque[i];
	std::cout << "\nTime to process a range of " <<  _deque.size() << " elements with std::deque  : " << dequeTime << " us" << std::endl;
	std::cout << "Time to process a range of " <<  _vector.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
}
