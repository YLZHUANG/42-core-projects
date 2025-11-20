#include "MutantStack.hpp"

int	main(void) {

	std::cout << "<<<<<<<<<< given test " << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
	++it; }

	std::stack<int> s(mstack); 

	std::cout << "<<< print the copy of 5, 3, 5, 737 in revert order" << std::endl;
	while (s.size()) {
		std::cout << s.top() << std::endl;
		s.pop(); }


	std::cout << "<<<<<<<<<< compare the MutantStack test to list " << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...] list.push_back(0);
	std::list<int>::iterator l_it = list.begin();
	std::list<int>::iterator l_ite = list.end();
	++l_it;
	--l_it;
	while (l_it != l_ite) {
		std::cout << *l_it << std::endl;
		++l_it; }

	return 0;

}