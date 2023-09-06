#include "Fixed.hpp"

Fixed::Fixed( void )
	: num (0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int integer ) {
	std::cout << "Int constructor called" << std::endl;
	this->num = integer << shift;
}

Fixed::Fixed( float floater ) {
	std::cout << "Float constructor called" << std::endl;
	this->num = (int)(roundf(floater * (1 << shift)));
}

Fixed::Fixed( const Fixed &source ) {
	std::cout << "Copy constructor called" << std::endl;
	this->num = source.getRawBits();
}

Fixed &Fixed::operator=( const Fixed &source ) {
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this != &source)
		this->num = source.getRawBits();
	return (*this);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return (this->num);
}

float Fixed::toFloat( void ) const {
	return (((float)(this->num)) / (1 << shift));
}

int Fixed::toInt( void ) const {
	return (this->num >> shift);
}

std::ostream &operator<<(std::ostream &out, const Fixed &source ) {
	out << source.toFloat();
	return (out);
}