#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point( );
		Point(const float n1,const float n2 );
		Point( const Point &source );
		Point &operator=( const Point &source );
		bool operator==( const Point &source ) const ;
		~Point( );
		Fixed getX( void ) const ;
		Fixed getY( void ) const ;
};

std::ostream&	operator<<(std::ostream& stream, Point const &obj);
bool bsp( Point const a, Point const b, Point const c, Point const point );
