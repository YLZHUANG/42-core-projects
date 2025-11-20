#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
//#include <stdexcept>
#include <cstdlib>

template<typename T>
class Array {

public:

	Array(void) : _array(NULL), _size(0) {};
	Array(unsigned int n) : _array(new T[n]()), _size(n) {};
	~Array() { 
		if (_array != NULL)
			delete[] _array;};
	Array(const Array<T>& copy){

		_size = copy._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = copy._array[i];}
	};

	Array<T>&	operator=(const Array<T>& other) {

	if (this != &other) {
		if (_array != NULL)
			delete[] _array;
		_size = other._size;
		if (_size) {
			_array = new T[_size];
			for (size_t i = 0; i < _size; i++) {
				_array[i] = other._array[i];
			}
		}
	}
	return (*this);};

	T& 	operator[](unsigned int i) {
	if (i < _size)
			return (_array[i]);
	else 
		throw (std::out_of_range("Exception: index is out of bounds."));};

	const T& 	operator[](unsigned int i) const {
	if (i < _size)
			return (_array[i]);
	else 
		throw (std::out_of_range("Exception: index is out of bounds."));};

unsigned int	size(void) const{ return (_size);};

private:
	T				*_array;
	unsigned int	_size;
};

#endif
