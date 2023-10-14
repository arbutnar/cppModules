#pragma once
#include <cstring>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

enum FormNames { Shrubbery, Robotomy, Presidential };

class Intern {
	private:
		static const	std::string forms[3] ;
	public:
		class CannotMakeForm;

		Intern( void );
		Intern( const Intern &src );
		Intern &operator=( const Intern &src );
		~Intern( void );

		AForm *makeForm( std::string name, std::string target );
};
