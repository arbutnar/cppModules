#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

class Fixed {

	private:
		int num;
		static const int shift = 8;
	public:
		Fixed( );
		Fixed( const int integer );
		Fixed( const float floater );
		Fixed( const Fixed &source );
		Fixed &operator=( const Fixed &source );
		~Fixed( );
		int getRawBits( void ) const;
		void setRawBits( const int bits );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &source );