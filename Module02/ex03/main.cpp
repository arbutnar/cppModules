#include "Fixed.hpp"
#include "Point.hpp"

int main( ) {

	Point a(0, 0); 
	Point b(3, 0); 
	Point c(0, 3); 
	Point point(0, 1);

	if (bsp(a,b,c, point))
		std::cout << "Given point inside this triangle area!" << std::endl;
	else
		std::cout << "Given point outside this triangle area!" << std::endl;
	return 0;
}