#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <sstream>

class BitcoinExchange {

public: 

	BitcoinExchange();
	BitcoinExchange(std::string csvFname);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	int								bitcoinExchange(std::string line);
	double							getResult( void );
	std::map<std::string, double>	getData( void );
	std::string						getValue( void );

private:

	std::string						_csvFname;
	std::string						_inputValue;
	std::map<std::string, double>	_data;
	std::map<std::string, double>	_csvData;
	double							_result;
	
	std::string	rmSpace(std::string str);
	std::string	mapData(std::string line, char d);
	void		checkDate(std::string str);
};

std::ostream &operator<<(std::ostream &os, BitcoinExchange &b);

#endif
