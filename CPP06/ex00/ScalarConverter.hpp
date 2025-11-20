
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <cmath>
# include <limits>
# include <iomanip>

class  ScalarConverter {

// private:

// 	ScalarConverter(void);
// 	ScalarConverter(const ScalarConverter &copy);
// 	~ScalarConverter(void);
// 	ScalarConverter &operator=(const ScalarConverter &other);

public:

	static void	convert(std::string v);

	class NoconversationException : public std::exception {
	public:
		virtual const char* what(void) const throw();};
};

#endif