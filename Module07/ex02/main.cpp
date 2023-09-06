#include "Array.hpp"

int main() {

	Array<int> ar1(5);

	Array<int> ar2;
	ar2 = ar1;

	ar1.displayElements();
	ar2.displayElements();
	std::cout << "size Array1 = " << ar1.getSize() << "\nsize Array2 = " << ar2.getSize() << std::endl;
	ar1.setElements(55);
	try {
		ar1[0] = 0;
		ar2[0] = 234;
		ar1.displayElements();
		ar2.displayElements();
	} catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	return 0;
}