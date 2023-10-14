#include "Intern.hpp"

int main() {
	try {
		Intern intern;
		AForm *form;
		form = intern.makeForm("PresidentialPardonForm", "balbio");
		delete (form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Intern intern;
		AForm *form;
		form = intern.makeForm("ShrubberyCreationForm", "balbio");
		delete (form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
