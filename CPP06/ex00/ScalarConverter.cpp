/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:04:20 by yzhuang           #+#    #+#             */
/*   Updated: 2024/12/09 11:17:22 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ScalarConverter::ScalarConverter(void) {}

// ScalarConverter::ScalarConverter(const ScalarConverter &copy) {

// 	*this = copy;
// }

// ScalarConverter::~ScalarConverter(void) {}

// ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {

// 	(void)other;
// 	return (*this);
// }

void	ScalarConverter::convert(std::string v)
{
	char	c;
	double	d;
	char	*endP;

	if (v.empty())
		return ;
	try
	{
		if (v.length() == 1 && !isdigit(v[0]))
		{		
			if (v[0] >= 32 && v[0] <= 126)
				std::cout << "char: " << v[0] << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}

		d = std::strtod(v.c_str(), &endP);
		if (std::isnan(d))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return;
		}

		if (std::isinf(d))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << ((d > 0)? "+inff" : "-inff") << std::endl;
			std::cout << "double : " << ((d > 0)? "+inf" : "-inf") << std::endl;
			return;
		}

		if ((endP == v && v.length() != 1) || (*endP == 'f' &&  *(endP + 1) != '\0') 
			|| (*endP != '\0' && *endP != 'f')
			|| (*endP == 'f' && *(endP + 1) == '\0' && v.find('.') == std::string::npos)
			|| (v.find_first_not_of("0123456789") == std::string::npos && v.length() > 27)
			|| (!d && v[0] == '-'))
			throw ScalarConverter::NoconversationException();


		c = static_cast<int>(d);
		if (isprint(c))
			std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << std::fixed << std::setprecision(1);
		if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		else
			throw ScalarConverter::NoconversationException();

		if (!d || (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max()))
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		else
			throw ScalarConverter::NoconversationException();

		std::cout << "double: " << d << std::endl;
	}
	catch (ScalarConverter::NoconversationException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char* ScalarConverter::NoconversationException::what(void) const throw() {

	return ("Sorry. The type conversion is impossible."); }
