#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() { return ("Grade too low"); }
};

class Bureaucrat::GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() { return ("Grade too high"); }
};

Bureaucrat::Bureaucrat( std::string name, int grade )
    : name (name), grade (grade) {
        if (this->grade < 1)
            throw Bureaucrat::GradeTooHighException();
        if (this->grade > 150)
            throw Bureaucrat::GradeTooLowException();
        std::cout << "Bureaucrat " << this->name << " with grade " << this->grade << " constructed" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src )
    : name (src.name) {
        std::cout << "Bureaucrat copy constructor from " << src.name << std::endl;
        *this = src;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &src ) {
    std::cout << "Copy assignment operator" << std::endl;
    if (this != &src)
        this->grade = src.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat( void ) {
    std::cout << "Bureaucrat decostructor called" << std::endl;
}

std::string Bureaucrat::getName( void ) {
    return (this->name);
}

int Bureaucrat::getGrade( void ) {
    return (this->grade);
}

void Bureaucrat::incrementGrade( int amount ) {
    for (int i = 0; i < amount; i++) {
        if (this->grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        this->grade -= 1;
    }
    std::cout << "Bureaucrat upgraded" << std::endl;
}

void Bureaucrat::decrementGrade( int amount ) {
    for (int i = 0; i < amount; i++) {
        if (this->grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        this->grade += 1;
    }
    std::cout << "Bureaucrat downgraded" << std::endl;
}

std::ostream &operator<<( std::ostream &os, Bureaucrat &b ) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return (os);
}
