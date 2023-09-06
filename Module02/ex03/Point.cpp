#include "Point.hpp"

Point::Point( )
	: x (0), y (0) {
}

Point::Point( const float f1, const float f2)
	: x(f1), y(f2) {
}

Point::Point( const Point &source )
	: x (source.x), y (source.y) {
}

Point	&Point::operator=( const Point &source ) {
	if (this == &source)
		return ( *this );
	return ( *this );
}

bool	Point::operator==( const Point &source ) const {
	if (this->getX() != source.getX() && this->getY() == source.getY())
		return ( false );
	return ( true );
}

Point::~Point( ) {

};

Fixed	Point::getX( void ) const {
	return (this->x);
}

Fixed	Point::getY( void ) const {
	return (this->y);
}

std::ostream&	operator<<(std::ostream& stream, Point const &obj) {
	stream << "x: " << obj.getX() << std::endl;
	stream << "y: " << obj.getY() << std::endl;
	return (stream);
}
