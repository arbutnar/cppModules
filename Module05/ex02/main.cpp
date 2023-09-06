#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	std::cout << "\033[1;33m=======ShrubberyCreationForm=======\033[0m\n";
	try {
		Bureaucrat	b("Balbio", 140);
		ShrubberyCreationForm f("prova");

		b.signForm(f);
		b.executeForm(f);
	} catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Bureaucrat	bb("BetterBalbio", 120);
		ShrubberyCreationForm f("28B");

		bb.signForm(f);
		bb.executeForm(f);
	} catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "\033[1;33m=======RobotomyRequestForm=======\033[0m\n";
	try {
		Bureaucrat	b("Balbio", 40);
		RobotomyRequestForm f("28C");

		b.signForm(f);
		b.executeForm(f);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[1;33m=======PresidentialPardonForm=======\033[0m\n";
	try {
		Bureaucrat	bb("BetterBalbio", 150);
		PresidentialPardonForm f("1A");

		bb.signForm(f);
		bb.executeForm(f);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	bbb("BestBetterBalbio", 1);
		PresidentialPardonForm f("1A");

		bbb.signForm(f);
		bbb.executeForm(f);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}