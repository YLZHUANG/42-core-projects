#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int i) {
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw (std::runtime_error("Value not found."));
	else
		return (it);};
	
#endif
