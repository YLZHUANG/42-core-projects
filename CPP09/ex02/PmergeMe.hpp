#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>

# define VALID_EXP "0123456789"

class PmergeMe {

public: 

	PmergeMe( void );
	~PmergeMe( void );
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &other);

	void	dSortPairs(std::deque<unsigned int> &a, std::deque<unsigned int> &b, std::deque<unsigned int> & numbers);
	void	dBinaryInsert(std::deque<unsigned int> &a, unsigned int b);
	void	dMergeInsert(std::deque<unsigned int> & numbers);

	void	vSortPairs(std::vector<unsigned int> &a, std::vector<unsigned int> &b, std::vector<unsigned int> & numbers);
	void	vBinaryInsert(std::vector<unsigned int> &a, unsigned int b);
	void	vMergeInsert(std::vector<unsigned int> & numbers);

	void	doPmergeMe( void );
	void	parseAndLoad(int ac, char **avs);

private:

	std::deque<unsigned int>	_rawDeque;
	std::deque<unsigned int>	_deque;

	std::vector<unsigned int>	_rawVector;
	std::vector<unsigned int>	_vector;
};

#endif
