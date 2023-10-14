#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: AForm ("PresidentialPradonForm", 25, 5), target (target) {
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src )
    : AForm(src.name, src.signGrade, src.execGrade) {
    *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &src ) {
    if (this != &src)
        this->target = src.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
}

std::string PresidentialPardonForm::getTarget( void ) {
	return (this->target);
}

void PresidentialPardonForm::execute( Bureaucrat const &executor ) const {
	AForm::execute(executor);
	try {
		Zaphod();
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void PresidentialPardonForm::Zaphod( void ) const {
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
