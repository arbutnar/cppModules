/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:04:28 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/07 17:28:01 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

std::ostream	&operator<<( std::ostream &os, const Scalar &rhs ) {
	os << "char: ";
	try {
		if ( std::isprint( rhs.getChar( ) ))
			os << '\'' << rhs.getChar( ) << '\'';
		else
			os << "Non displayable";
	}
	catch(std::exception &e) {
		os << e.what( );
	}
	os << std::endl;
	os << "int: ";
	try {
		os << rhs.getInt( );
	}
	catch(std::exception &e) {
		os << e.what( );
	}
	os << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	os << "float: ";
	try {
		os << rhs.getFloat( ) << 'f';
	}
	catch(std::exception &e) {
		os << e.what( );
	}
	os << std::endl;
	os << "double: ";
	try {
		os << rhs.getDouble( );
	}
	catch(std::exception &e) {
		os << e.what( );
	}
	return os;
}

Scalar::Scalar( void )
	: literal ( "none" ) {
		status = invalid;
		type = invalidType;
}

Scalar::Scalar( char *str )
	: literal ( static_cast<std::string> ( str ) ) {
		status = detectStatus( );
		type = detectType( );
		if (type != invalidType)
			status = valid;
		switch(type) {
			case charType:
				fromChar( );
				break;
			case intType:
				fromInt( );
				break;
			case floatType:
				fromFloat( );
				break;
			case doubleType:
				fromDouble( );
				break;
			default:
				return ;
		}
}

Scalar::Scalar( const Scalar &src ) {
	*this = src;
}

Scalar::~Scalar( void ) {
	
}

Scalar	&Scalar::operator=( const Scalar &rhs ) {
	if (this == &rhs)
		return *this;
	this->literal = rhs.literal;
	return *this;
}

std::string	Scalar::getLiteral( void ) const {
	return this->literal;
}

char	Scalar::getChar( void ) const {
	switch (status) {
		case invalid:
		case nan:
		case nanf:
		case negInf:
		case posInf:
			throw impossibleException( );
		default:
			return this->charValue;
	}
}

int	Scalar::getInt( void ) const {
	switch (status) {
		case invalid:
		case nan:
		case nanf:
		case negInf:
		case posInf:
			throw impossibleException( );
		default:
			return this->intValue;
	}
}

float	Scalar::getFloat( void ) const {
	switch (status) {
		case invalid:
			throw impossibleException( );
		case negInf:
			throw negInfException( );
		case posInf:
			throw posInfException( );
		case nan:
		case nanf:
			throw nanfException( );
		default:
			return this->floatValue;
	}
}

double	Scalar::getDouble( void ) const {
	switch (status) {
		case invalid:
			throw impossibleException( );
		case negInf:
			throw negInfException( );
		case posInf:
			throw posInfException( );
		case nan:
		case nanf:
			throw nanException( );
		default:
			return this->doubleValue;
	}
}

int	Scalar::detectStatus( void ) const {
	std::string status[] = {"inf", "+inf", "-inf", "nan", "nanf", "null"};
	int	i = 0;

	for (; i < 6; i++) {
		if (literal == status[i])
			break ;
	}
	switch (i) {
		case 0:
		case 1:
			return posInf;
		case 2:
			return negInf;
		case 3:
			return nan;
		case 4:
			return nanf;
		default:
			return invalid;
	}
}

int	Scalar::detectType( void ) const {
	if (status != invalid)
		return invalidType;
	if (literal.length( ) == 1)
	{
		if ( std::isdigit(literal.at(0)) )
			return intType;
		else
			return charType;
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
					return invalidType;
			}
			if (literal.at(i) == 'f')
				return floatType;
			else if (std::isdigit( literal.at(i)))
				return doubleType;
			return invalidType;
		}
		else if(!std::isdigit( literal.at(i) ))
			return invalidType;
	}
	return intType;
}

void	Scalar::fromChar( void ) {
	charValue = literal.at(0);
	intValue = static_cast <int> ( charValue );
	floatValue = static_cast <float> ( charValue );
	doubleValue = static_cast <double> ( charValue );
}

void	Scalar::fromInt( void ) {
	intValue = std::atoi( literal.c_str() );
	charValue = static_cast <char> ( intValue );
	floatValue = static_cast <float> ( intValue );
	doubleValue = static_cast <double> ( intValue );
}

void	Scalar::fromFloat( void ) {
	floatValue = std::atof( literal.c_str() );
	charValue = static_cast <char> ( floatValue );
	intValue = static_cast <int> ( floatValue );
	doubleValue = static_cast <double> ( floatValue );
}

void	Scalar::fromDouble( void ) {
	doubleValue = std::atof( literal.c_str() );
	charValue = static_cast <char> ( doubleValue );
	intValue = static_cast <int> ( doubleValue );
	floatValue = static_cast <float> ( doubleValue );
}

const char *Scalar::impossibleException::what( void ) const throw( ) {
	return "impossible";
}

const char *Scalar::negInfException::what( void ) const throw( ) {
	return "-inf";
}

const char *Scalar::posInfException::what( void ) const throw( ) {
	return "+inf";
}

const char *Scalar::nanException::what( void ) const throw( ) {
	return "nan";
}

const char *Scalar::nanfException::what( void ) const throw( ) {
	return "nanf";
}