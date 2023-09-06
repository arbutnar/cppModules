#pragma once
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        class GradeTooLowException;
        class GradeTooHighException;

        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const ;
        void incrementGrade(int amount);
        void decrementGrade(int amount);

        void signForm(AForm &form);
        void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &b);
