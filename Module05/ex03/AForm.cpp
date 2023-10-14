#include "AForm.hpp"

class AForm::GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() { return ("\033[1;31mGrade too low\033[0m"); } 
};

class AForm::GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() { return ("\033[1;31mGrade too high\033[0m"); }
};

class AForm::notSigned : public std::exception {
	public:
		virtual const char* what() const throw() { return ("\033[1;31mForm not signed\033[0m"); }
};

AForm::AForm( void )
	: name ("Unnamed"), isSigned (false), signGrade(0), execGrade(0) {
}

AForm::AForm ( std::string n, int gts, int gte )
	: name (n), isSigned (false), signGrade(gts), execGrade(gte) {
	if (this->signGrade < 1 || this->execGrade < 1)
        throw AForm::GradeTooHighException();
    if (this->signGrade > 150 || this->execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm &src )
	: name (src.name), isSigned (src.isSigned), signGrade(src.signGrade), execGrade(src.execGrade) {
	*this = src;
}

AForm &AForm::operator=( const AForm &src ) {
	if (this == &src)
		return (*this);
	return (*this);
}

AForm::~AForm( void ) {
}

std::string AForm::getName( void ) const {
	return (this->name);
}

bool AForm::getIsSigned( void ) const {
	return (this->isSigned);
}

void AForm::setIsSigned( bool state ) {
	this->isSigned = state;
}

int AForm::getSignGrade( void ) const {
	return (this->signGrade);
}

int AForm::getExecGrade( void ) const {
	return (this->execGrade);
}

void AForm::beSigned( Bureaucrat *b ) {
	std::cout << "AFORM PROSPECTIVE: Requested grade to sign AForm: " << this->getSignGrade() << std::endl;
	if (b->getGrade() <= this->getSignGrade()) {
		this->isSigned = true;
		std::cout << "Candidate for signing: " << *b; 
		std::cout << "AForm signed state: " << std::boolalpha << this->getIsSigned() << std::endl;
	}
	else {
		std::cout << "Candidate for signing: " << *b; 
		throw AForm::GradeTooLowException();
	}
}

void AForm::execute( Bureaucrat const &executor ) const {
	if (!this->isSigned)
		throw AForm::notSigned();
	else if (executor.getGrade() > this->getExecGrade()) {
		std::cout << executor.getName() << " couldn’t execute " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<( std::ostream &os, AForm &f ) {
	os << "AForm name: " << f.getName() << ".\nsigned state: " << f.getIsSigned() << ".\ngrade required to sign: " << f.getSignGrade() << ".\ngrade required to execute: " << f.getExecGrade() << ".\n";
	return (os);
}
