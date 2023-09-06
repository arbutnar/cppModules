#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int execGrade;
	
	public:
		class GradeTooLowException;
		class GradeTooHighException;
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &src);
        Form &operator=(const Form &src);
		~Form();

		std::string getName() const;
		bool getIsSigned();
		void setIsSigned(bool state);
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat *b);

};

std::ostream &operator<<(std::ostream &os, Form &f);