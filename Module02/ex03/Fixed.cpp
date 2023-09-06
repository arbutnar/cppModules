#include "Fixed.hpp"

Fixed::Fixed( void )
	: value (0) {
}

Fixed::Fixed( const int integer ) {
	this->value = integer << shift;
}

Fixed::Fixed( float floater ) {
	this->value = (int)(roundf(floater * (1 << shift)));
}

Fixed::Fixed( const Fixed &source ) {
	this->value = source.getRawBits();
}

Fixed &Fixed::operator=( const Fixed &source ) {
	if (this != &source)
		this->value = source.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+( const Fixed &source ) const {
	Fixed res;
	int rawBits;

	rawBits = this->value + source.value;
	res.setRawBits(rawBits);
	return (res);
}

Fixed	Fixed::operator-( const Fixed &source ) const {
	Fixed res;
	int rawBits;

	rawBits = this->value - source.value;
	res.setRawBits(rawBits);
	return (res);
}

Fixed	Fixed::operator*( const Fixed &source ) const {
	Fixed res;
	int rawBits;

	rawBits = this->value * source.value / (1 << source.shift);
	res.setRawBits(rawBits);
	return (res);
}

Fixed	Fixed::operator/( const Fixed &source ) const {
	Fixed res;
	int rawBits;

	rawBits = this->value / (source.value / (1 << source.shift));
	res.setRawBits(rawBits);
	return (res); 
}

bool	Fixed::operator>( const Fixed &source ) const {
	if (this->value < source.value)
		return false;
	return true;
}
bool	Fixed::operator<( const Fixed &source ) const {
	if (this->value > source.value)
		return false;
	return true;
}

bool	Fixed::operator>=( const Fixed &source ) const {
	if (this->value < source.value)
		return false;
	return true;
}

bool	Fixed::operator<=( const Fixed &source ) const {
	if (this->value > source.value)
		return false;
	return true;
}

bool	Fixed::operator==( const Fixed &source ) const {
	if (this->value != source.value)
		return false;
	return true;
}

bool	Fixed::operator!=( const Fixed &source ) const {
	if (this->value == source.value)
		return false;
	return true;
}

Fixed Fixed::operator++( ) {
	this->value++;
	return (*this);
}

Fixed Fixed::operator++( int ) {
	Fixed temp(*this);
	this->value++;
	return (temp);
}

Fixed Fixed::operator--( ) {
	this->value--;
	return (*this);
}

Fixed Fixed::operator--( int ) {
	Fixed temp(*this);
	this->value--;
	return (temp);
}

Fixed::~Fixed( void ) {

}

void	Fixed::setRawBits(const int bits) {
	this->value = bits;
}

int	Fixed::getRawBits(void) const {
	return (this->value);
}

float Fixed::toFloat( void ) const {
	return (((float)(this->value)) / (1 << shift));
}

int Fixed::toInt( void ) const {
	return (this->value >> shift);
}

Fixed &Fixed::min(Fixed& n1, Fixed& n2) {
	if ( n1 <= n2 )
		return (n1);
	return (n2);
}

Fixed const &Fixed::min(Fixed const & n1, Fixed const & n2) {
	if ( n1 <= n2 )
		return (n1);
	return (n2);
}

Fixed &Fixed::max(Fixed& n1, Fixed& n2) {
	if ( n1 >= n2 )
		return (n1);
	return (n2);
}

Fixed const &Fixed::max(Fixed const & n1, Fixed const & n2) {
	if ( n1 >= n2 )
		return (n1);
	return (n2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &source ) {
	out << source.toFloat();
	return (out);
}