#include "Intern.hpp"

class Intern::CannotMakeForm : public std::exception {
	public:
		virtual const char* what() const throw() { return("\033[1;31mCannot make form with given name\033[0m"); }
};

const std::string Intern::forms[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
};

Intern::Intern( const Intern &src ) {
	*this = src;
}

Intern &Intern::operator=( const Intern &src ) {
	if (this == &src)
		return (*this);
	return (*this);
}

Intern::~Intern( void ) {
}

AForm *Intern::makeForm( std::string name, std::string target ) {
	int idx;

	for(idx = 0; idx < 3; idx++) {
		if (this->forms[idx] == name) {
			std::cout << "Intern creates " << this->forms[idx] << std::endl;
			break ;
		}
	}
	if (idx == 3) {
        throw Intern::CannotMakeForm();
    }
	
	FormNames form = FormNames(idx);
	switch (form) {
		case Shrubbery :
			return (new ShrubberyCreationForm(target));
		case Robotomy :
			return (new RobotomyRequestForm(target));
		case Presidential :
			return (new PresidentialPardonForm(target));
		default :
			throw Intern::CannotMakeForm();
	}
	return (NULL);
}
