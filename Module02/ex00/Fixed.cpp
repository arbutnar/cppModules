#include "Fixed.hpp"

Fixed::Fixed()
	: num (0) {
		setRawBits(0);
		std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &source) {
	std::cout << "Copy constructor called\n";
	*this = source;
}

// assignment accurs when an object has already been initialized
// and we want to assign another obj to it. There is a default one;
Fixed &Fixed::operator=(const Fixed &source) {
	//the obj on the left-hand side of the operator is refered to by the this pointer
	//and the obj on the right-hand side is being passed into the method;
	// the left-hand side object will be overwritten
	std::cout << "Copy assignment operator called\n";
	//if (this == &source)
	this->num = source.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
};

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (this->num);
}

void	Fixed::setRawBits(int const raw) {
	this->num = raw; 
}
