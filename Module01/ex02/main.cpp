#include <iostream>

int main() {
	std::string			string = "HI THIS IS BRAIN";
	const std::string	*stringPTR = &string;
	const std::string	&stringREF = string;

	std::cout << "Address of string: " << &string << std::endl;
	std::cout << "Adress held by stringPTR: " << &stringPTR << std::endl;
	std::cout << "Adress held by stringREF: " << &stringREF << std::endl;

	std::cout << "================================================\n";
	std::cout << "Value of string: " << string << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF: " << stringREF << std::endl;
	return 0;
}
