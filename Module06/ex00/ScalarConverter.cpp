/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:04:28 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/08 18:34:35 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::_literal = "none";
Pseudo		ScalarConverter::_pseudo;
int			ScalarConverter::_type = 0;
char		ScalarConverter::_charValue = '\0';
int			ScalarConverter::_intValue = 0;
float		ScalarConverter::_floatValue = 0.0f;
double		ScalarConverter::_doubleValue = 0.0;

void	ScalarConverter::convert( char *literal ) {

	_literal = static_cast<std::string>(literal);
	detectPseudo( );
	try {
		_type = detectType( );
	} catch (std::invalid_argument const &e) {
		std::cout << e.what() << std::endl;
		return ;
	}
	if (_type != NOTYPE) {
		switch(_type) {
			case CHAR:
				fromChar( );
				break ;
			case INT:
				fromInt( );
				break ;
			case FLOAT:
				fromFloat( );
				break ;
			case DOUBLE:
				fromDouble( );
				break ;
			default:
				return ;
		}
	}
	display();
}

void	ScalarConverter::display() {

	std::cout << "char: ";
	try {
		if ( std::isprint( getChar( ) ))
			std::cout << '\'' << getChar( ) << '\'';
		else
			std::cout << "Non displayable";
	}
	catch(std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "int: ";
	try {
		std::cout << getInt( );
	}
	catch(std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: ";
	try {
		std::cout << getFloat( ) << 'f';
	}
	catch(std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "double: ";
	try {
		std::cout << getDouble( ) << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::string	ScalarConverter::getLiteral( void ) {
	return _literal;
}

char	ScalarConverter::getChar( void ) {
	switch (_pseudo) {
		case NAN:
		case NANF:
		case NEGINF:
		case POSINF:
			throw impossibleException( );
		default:
			return ScalarConverter::_charValue;
	}
}

int	ScalarConverter::getInt( void ) {
	switch (_pseudo) {
		case NAN:
		case NANF:
		case NEGINF:
		case POSINF:
			throw impossibleException( );
		default:
			return ScalarConverter::_intValue;
	}
}

float	ScalarConverter::getFloat( void ) {
	switch (_pseudo) {
		case NEGINF:
			throw negInfException( );
		case POSINF:
			throw posInfException( );
		case NAN:
		case NANF:
			throw nanfException( );
		default:
			return ScalarConverter::_floatValue;
	}
}

double	ScalarConverter::getDouble( void ) {
	switch (_pseudo) {
		case NEGINF:
			throw negInfException( );
		case POSINF:
			throw posInfException( );
		case NAN:
		case NANF:
			throw nanException( );
		default:
			return ScalarConverter::_doubleValue;
	}
}

void	ScalarConverter::detectPseudo( void ) {
	std::string status[] = { "inf", "+inf", "-inf", "nan", "nanf" };
	int	i;

	for (i = 0; i < 5; i++) {
		if (_literal == status[i])
			break ;
	}
	switch (i) {
		case 0:
		case 1:
			_pseudo = POSINF;
			break ;
		case 2:
			_pseudo = NEGINF;
			break ;
		case 3:
			_pseudo = NAN;
			break ;
		case 4:
			_pseudo = NANF;
			break ;
		default:
			_pseudo = NOPSEUDO;
	}
}

int	ScalarConverter::detectType( void ) {
	if (_pseudo != NOPSEUDO)
		return NOTYPE;
	if (_literal.length( ) == 1)
	{
		if ( std::isdigit(_literal.at(0)) )
			return INT;
		else
			return CHAR;
	}
	long unsigned int	i = 0;
	if (_literal.at(0) == '+' || _literal.at(0) == '-')
		i += 1;
	for(; i < _literal.length( ); i++)
	{
		if (_literal.at(i) == '.')
		{
			i += 1;
			for(; i < _literal.length( ) - 1; i++)
			{
				if (!std::isdigit( _literal.at(i) ))
					return NOTYPE;
			}
			if (_literal.at(i) == 'f')
				return FLOAT;
			else if (std::isdigit( _literal.at(i)))
				return DOUBLE;
			return NOTYPE;
		}
		else if(!std::isdigit( _literal.at(i) ))
			throw std::invalid_argument("Invalid Argument");
	}
	return INT;
}

void	ScalarConverter::fromChar( void ) {
	_charValue = _literal.at(0);
	_intValue = static_cast <int> ( _charValue );
	_floatValue = static_cast <float> ( _charValue );
	_doubleValue = static_cast <double> ( _charValue );
}

void	ScalarConverter::fromInt( void ) {
	_intValue = std::atoi( _literal.c_str() );
	_charValue = static_cast <char> ( _intValue );
	_floatValue = static_cast <float> ( _intValue );
	_doubleValue = static_cast <double> ( _intValue );
}

void	ScalarConverter::fromFloat( void ) {
	_floatValue = std::atof( _literal.c_str() );
	_charValue = static_cast <char> ( _floatValue );
	_intValue = static_cast <int> ( _floatValue );
	_doubleValue = static_cast <double> ( _floatValue );
}

void	ScalarConverter::fromDouble( void ) {
	_doubleValue = std::atof( _literal.c_str() );
	_charValue = static_cast <char> ( _doubleValue );
	_intValue = static_cast <int> ( _doubleValue );
	_floatValue = static_cast <float> ( _doubleValue );
}

const char *ScalarConverter::impossibleException::what( void ) const throw( ) {
	return "impossible";
}

const char *ScalarConverter::negInfException::what( void ) const throw( ) {
	return "-inf";
}

const char *ScalarConverter::posInfException::what( void ) const throw( ) {
	return "+inf";
}

const char *ScalarConverter::nanException::what( void ) const throw( ) {
	return "nan";
}

const char *ScalarConverter::nanfException::what( void ) const throw( ) {
	return "nanf";
}