/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:29:19 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/11 16:41:29 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// EXCEPTIONS
class	BitcoinExchange::CannotOpenFile : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Error: could not open file."); } 
};

class	BitcoinExchange::DataError : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Error: incorrect, inconsistent, or corrupted Data set."); } 
};

class	BitcoinExchange::DataInvalidValue : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Error: invalid value in Data set."); } 
};

class	BitcoinExchange::InputError : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Error: incorrect, inconsistent, or corrupted Input file."); } 
};

// COPLIEN
BitcoinExchange::BitcoinExchange( void ) {
	throw BitcoinExchange::CannotOpenFile();
}

BitcoinExchange::BitcoinExchange( const char* filename ) {
	std::ifstream	data(filename);
	std::string	line;
	std::string	date;
	double	value;
	char	sep;
	
	if (!data.is_open())
		throw CannotOpenFile();

	std::getline(data, line);
	if(line.compare(0, 4, "date") || line.compare(5, 13, "exchange_rate"))
		throw DataError();
	sep = line.at(4);
	while(std::getline(data, date, sep))
	{
		std::getline(data, line);
		std::istringstream(line) >> value;
		if (checkPair(date, line) || (value < 0.0 || value >= 2147483647))
			throw DataError();
		_exchangeMap.insert(std::pair<std::string, double>(date, value));
	}
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &src )
	: _exchangeMap (src._exchangeMap) {
}

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange &src ) {
	if (this != &src)
		this->_exchangeMap = src._exchangeMap;
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void ) {
	_exchangeMap.clear();
}

// FUNCS
int	BitcoinExchange::checkPair( std::string const &date, std::string const &value ) {
	if (date.find_first_not_of("0123456789-") != std::string::npos)
		return 1;
	
	std::string	ymd[3];
	ymd[0] = date.substr(0, 4);
	ymd[1] = date.substr(5, 2);
	ymd[2] = date.substr(8, 2);
	if (ymd[0].length() != 4 || ymd[1].length() != 2 || ymd[2].length() != 2)
		return 1;

	double n;	
	std::istringstream(ymd[0]) >> n;
	if (n <= 0 || n >= 2147483647)
		return 1;
	std::istringstream(ymd[1]) >> n;
	if (n <= 0 || n > 12)
		return 1;
	std::istringstream(ymd[2]) >> n;
	if (n <= 0 || n > 31)
		return 1;

	if (value.find_first_not_of("0123456789.-+") != std::string::npos
		|| std::count(value.begin(), value.end(), '.') > 1)
		return 1;

	std::istringstream(value) >> n;
	if (n < 0)
		return 2;
	else if (n >= 2147483647)
		return 3;

	return 0;
}

void	BitcoinExchange::exchange( const char *filename ) {
	std::ifstream	input(filename);
	std::string		line;
	std::string		date;
	std::string		value;
	double			n;
	int 			ret;

	if (!input.is_open())
		throw CannotOpenFile();
	while (std::getline(input, line))
	{
		if (line == "date | value")
			continue ;
		if (line.length() < 13 || line.substr(10, 3) != " | ")
			ret = 1;
		else
		{
			date = line.substr(0, 10);
			value = line.substr(13);
			std::replace(value.begin(), value.end(), ',', '.');
			ret = checkPair(date, value);
		}
		switch(ret) {
		case 1:
			std::cout << "Error: bad input => " << line << std::endl;
			break;
		case 2:
			std::cout << "Error: not a positive number." << std::endl;
			break;
		case 3:
			std::cout << "Error: too large a number." << std::endl;
			break;
		default:
			std::map<std::string, double>::iterator it = _exchangeMap.lower_bound(date);
			if (date != it->first)
				  it--;
			std::istringstream(value) >> n;
			std::cout << date << " => " << n << " = " <<  n * it->second << std::endl;
		}
	}
}
