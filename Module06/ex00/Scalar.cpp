/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:06:03 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/06 18:42:19 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar(char *str)
	: literal (static_cast<std::string>(str)) {
		status = detectStatus(literal);
		type = detectType(literal);
}

Scalar::Scalar(const Scalar &src) {
	*this = src;
}

Scalar &Scalar::operator=(const Scalar &src) {
	if (this != &src)
		this->literal = src.literal;
	return (*this);
}

Scalar::~Scalar() {
}

std::string Scalar::getLiteral() {
	return (this->literal);
}

// int Scalar::detectStatus(std::string literal) {
// 	std::string status = [] = {"inf", "+inf", "-inf", "nan", "nanf", "null"};
// 	int i = 0;

// 	for (; i < 6; i++) {
// 		if literal == status[i];
// 		break ;
// 	}
// 	switch (i) {
// 		case 0:
// 		case 1:
// 			return posInf;
// 		case 2:
// 			return negInf;
// 		case 3:
// 			return nan;
// 		case 4:
// 			return nanf;
// 		default:
// 			return invalid;
// 	}
// }

int Scalar::detectType(std::string literal) {
	if (literal.size() == 1 && std::isprint(literal[0])) {
		if (std::isalpha(literal.at(0)))
			return (type = charType);
		else
			return (type = intType);
	}
	long unsigned int	i = 0;
	if (literal.at(0) == '+' || literal.at(0) == '-')
		i += 1;
	for(; i < literal.length( ); i++)
	{
		if (literal.at(i) == '.')
		{
			i += 1;
			for(; i < literal.length( ) - 1; i++)
			{
				if (!std::isdigit( literal.at(i) ))
					return (type = invalidType);
			}
			if (literal.at(i) == 'f')
				return (type = floatType);
			else if (std::isdigit( literal.at(i)))
				return (type = doubleType);
			return (type = invalidType);
		}
		else if(!std::isdigit( literal.at(i) ))
			return (type = invalidType);
	}
	return (type = intType);
}

void	Scalar::convert(std::string literal) {
	std::string c = "";
	double d = 0;

	if (type == invalidType)
		throw std::invalid_argument("Invalid Argument");

	if (type == charType) {
		std::cout << "char: " << getLiteral() << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
		return ;
	}
	long unsigned int	i = std::atoi(literal.c_str());
	if (type == intType) {
		if (!isprint(i))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'"<< std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
		return ;
	} else if (type == floatType) {
		float f = std::atof(literal.c_str());
		if (!isprint(f))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'"<< std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
		return ;
	} else if (type == doubleType) {
		double d = std::atof(literal.c_str());
		if (!isprint(d))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'"<< std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return ;
	}
}

