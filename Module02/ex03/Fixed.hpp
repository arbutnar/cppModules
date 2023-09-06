#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

class Fixed {

	private:
		int value;
		static const int shift = 8;
	public:
		Fixed( );
		Fixed( const int integer );
		Fixed( const float floater );
		Fixed( const Fixed &source );
		~Fixed( );
		Fixed &operator=( const Fixed &source );

		Fixed operator+( const Fixed &source ) const;
		Fixed operator-( const Fixed &source ) const;
		Fixed operator*( const Fixed &source ) const ;

		Fixed operator/( const Fixed &source ) const;
		bool operator>( const Fixed &source ) const;
		bool operator<( const Fixed &source ) const;
		bool operator>=( const Fixed &source ) const;
		bool operator<=( const Fixed &source ) const;
		bool operator==( const Fixed &source ) const;
		bool operator!=( const Fixed &source ) const;

		Fixed operator++( );
		Fixed operator++( int );
		Fixed operator--( );
		Fixed operator--( int );
	
		int getRawBits( void ) const;
		void setRawBits( const int bits );
		float toFloat( void ) const;
		int toInt( void ) const;
	
		static Fixed &min(Fixed& f1, Fixed& f2);
		static Fixed &max(Fixed& f1, Fixed& f2);
		static Fixed const &min(Fixed const & f1, Fixed const & f2);
		static Fixed const &max(Fixed const & f1, Fixed const & f2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &source );