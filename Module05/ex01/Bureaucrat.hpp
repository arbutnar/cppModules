#pragma once
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

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

        std::string getName();
        int getGrade();
        void incrementGrade(int amount);
        void decrementGrade(int amount);

        void signForm(Form *f);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &b);
