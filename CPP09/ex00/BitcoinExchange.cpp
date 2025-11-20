#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string csvFname): _csvFname(csvFname) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_csvFname = other._csvFname;
		_data = other._data;
		_csvData = other._csvData;
		_result = other._result;
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy): 
	_csvFname(copy._csvFname), _data(copy._data), _csvData(copy._csvData),
	 _result(copy._result) {}

int BitcoinExchange::bitcoinExchange(std::string inLine) {

	std::string csvLine;
	std::string csvDate;
	std::string lastDate;
	std::map<std::string, double> lastData;

	try
	{
		std::fstream csv(_csvFname.c_str());
		if (!csv)
			throw (std::runtime_error("Can not open csv file"));

		std::string date = mapData(inLine, '|');
		if (date < "2010-08-20" || date > "2022-03-29") {
			std::cout << date << " => data not available" << std::endl;
			return (1);
		}
		
		std::getline(csv, csvLine);
		while (std::getline(csv, csvLine))
		{
			if (csvLine.empty())
				continue ;
			csvDate = mapData(csvLine, ',');
			if (date <= csvDate) {
				if (date == csvDate)
					_result = _data[date] * _csvData[csvDate];
				else
					_result = _data[date] * lastData[lastDate];
				csv.close();
				return (0);
			}
			lastDate = csvDate;
			lastData = _csvData;
		}
		csv.close();
		return (-1);
	}
	catch(const std::runtime_error &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (1);
}

std::string	BitcoinExchange::rmSpace(std::string str) {

	str.erase(0, str.find_first_not_of(' '));
	if (str.empty())
		throw std::runtime_error("Error: bad input");

	size_t pos = str.find_last_not_of(' ');

	// check if ("  sth sth " instead of "  sth   ")
	for (size_t i = pos + 1; str[i]; i++) {
		if (str[i] && str[i] != ' ')
			throw std::runtime_error("Error: bad input");
		}

	str.erase(pos + 1);
	return (str);
}

std::string	BitcoinExchange::mapData(std::string line, char d) {

	size_t	dNum = 0;
	size_t	i;
	size_t	dPos = line.find(d);
	char	*endP = 0;

	if (d == '|') {
		for (i = 0; line[i]; i++) {
			if (line[i] == d)
					dNum++;
		}
		if (dNum > 1 || !dPos)
			throw std::runtime_error("Error: bad input : |");
	}

	std::string date = rmSpace(line.substr(0, dPos));
	std::string value = rmSpace(line.substr(dPos + 1));

	if (d == ',') {
		_csvData.clear();
		_csvData[date] = strtod(value.c_str(), &endP);
		return (date);
	}

	if (value[0] == '-')
		throw std::runtime_error("Error: not a positive number.");
	checkDate(date);
	_data.clear();
	_data[date] = strtod(value.c_str(), &endP);
	if (*endP != '\0' || endP == value.c_str())
		throw std::runtime_error("Error: bad input.");
	else if (_data[date] >= 2147483648)
		throw std::runtime_error("Error: too large a number.");
	_inputValue = value;
	return (date);
}

void		BitcoinExchange::checkDate(std::string str) {

	size_t	i = 0;
	int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (str.size() != 10 || str[4] != '-' || str[7] != '-')
		throw std::runtime_error("Error: bad input format => " + str);
	while (str[i] && isdigit(str[i]))
		i++;
	if	(i != 4 || str[i] != '-')
		throw std::runtime_error("Error: bad input => " + str);
	i++;
	while (str[i] && isdigit(str[i]))
		i++;
	if	(i != 7 || str[i] != '-')
		throw std::runtime_error("Error: bad input => " + str);
	i++;
	while (str[i] && isdigit(str[i]))
		i++;
	if	(i != 10 || str[i])
		throw std::runtime_error("Error: bad input => " + str);

	int year = atoi(str.substr(0, 4).c_str());
	int month = atoi(str.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		throw std::runtime_error("Error: bad input => " + str);

	int day = atoi(str.substr(8, 2).c_str());
	if (day < 1 || day > days[month - 1] || (!year % 4 && day > 28))
		throw std::runtime_error("Error: bad input => " + str);
}

double	BitcoinExchange::getResult( void ) { return (_result); }

std::map<std::string, double> BitcoinExchange::getData( void ) { return (_data); }

std::string	BitcoinExchange::getValue( void ) { return (_inputValue); }

std::ostream &operator<<(std::ostream &os, BitcoinExchange &b) {

	std::map<std::string, double> data = b.getData();
	double	result = b.getResult();
	std::ostringstream oss;
	oss << result;
	std::string resultStr = oss.str();
	size_t pos = resultStr.find('.');

	for (std::map<std::string, double>::iterator i = data.begin(); i != data.end(); i++)
		if (pos != resultStr.npos && resultStr.substr(pos + 1).size() > 2)
			os << i->first << " => " << b.getValue() << " = " << std::fixed << std::setprecision(2) << b.getResult();
		else
			os << i->first << " => " << b.getValue() << " = " << b.getResult();
	return (os);
}
