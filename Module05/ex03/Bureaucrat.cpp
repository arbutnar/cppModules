#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() { return ("\033[1;31mGrade too low\033[0m"); }
};

class Bureaucrat::GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() { return ("\033[1;31mGrade too high\033[0m"); }
};

Bureaucrat::Bureaucrat(std::string name, int grade)
    : name (name), grade (grade) {
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
    if (this == &src)
        return (*this);
    this->grade = src.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {

}

std::string Bureaucrat::getName() const {
    return (this->name);
}

int Bureaucrat::getGrade() const {
    return (this->grade);
}

void Bureaucrat::incrementGrade(int amount) {
    for (int i = 0; i < amount; i++) {
        if (this->grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        this->grade -= 1;
    }
    std::cout << "Bureaucrat upgraded at " << this->grade << std::endl;
}

void Bureaucrat::decrementGrade(int amount) {
    for (int i = 0; i < amount; i++) {
        if (this->grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        this->grade += 1;
    }
    std::cout << "Bureaucrat downgraded at " << this->grade << std::endl;
}

void    Bureaucrat::signForm(AForm &form) {
    if (this->getGrade() <= form.getSignGrade()) {
        form.setIsSigned(true);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } else {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because ";
        throw Bureaucrat::GradeTooLowException();
    }
}

void    Bureaucrat::executeForm(AForm const &form) {
    if (this->getGrade() <= form.getExecGrade()) {
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
        form.execute(*this);
    }
    else {
        std::cout << this->getName() << " couldn’t execute " << form.getName() << " because ";
        throw Bureaucrat::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return (os);
}
