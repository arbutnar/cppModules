/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:29:19 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/10 17:51:08 by arbutnar         ###   ########.fr       */
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

// COPLIEN
BitcoinExchange::BitcoinExchange( char* filename ) {
	std::ifstream input(filename);

	if (!input.is_open())
		throw BitcoinExchange::CannotOpenFile();

	std::fstream data("data.csv");
	std::string	date;
	std::string	exRate;

	std::getline(data, date);
	if(date.compare(0, 4, "date") || date.compare(5, 13, "exchange_rate"))
		 throw BitcoinExchange::DataError();

	double	value;
	char	sep = date.at(4);
	std::istringstream(exRate) >> value;

	while (std::getline(data, date, sep))
	{
		std::getline(data, exRate);
		if (checkPair(date, exRate) == 1)
			throw BitcoinExchange::DataError();
		else if (checkPair(date, exRate) == 2)
			throw BitcoinExchange::DataInvalidValue();
		else
			std::map.insert(std::make_pair(date, value))
	}
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &src ) {
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange &src ) {
	if (this != src)
		this->map = src.map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void ) { }

// FUNCS
int	BitcoinExchange::checkPair( std::string date, std::string value ) {
	if (date.find_first_not_of("0123456789-") != std::string::npos)
		return 1;

	std::string	ymd[3];
	ymd[0] = date.substr(0, 4);
	ymd[1] = date.substr(5, 2);
	ymd[2] = date.substr(8, 2);
	if (ymd[0].length() != 4 || ymd[1].length() != 2 || ymd[2].length() != 2)
		return 1;

	double	n;
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
			return 2;
	std:istringstream(value) >> n;
	if (n < 0 || n >= 2147483647)
		return 2;

	return 0;
}

void	BitcoinExchange::exchange( std::string filename ) {
	
}
