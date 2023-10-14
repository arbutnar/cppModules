#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool			isSigned;
		const int		signGrade;
		const int		execGrade;
	public:
		class GradeTooLowException;
		class GradeTooHighException;

		Form( void );
		Form( std::string name, int signGrade, int execGrade );
		Form( const Form &src );
        	Form &operator=( const Form &src );
		~Form( void );

		std::string getName( void ) const;
		bool getIsSigned( void );
		void setIsSigned( bool state );
		int getSignGrade( void ) const;
		int getExecGrade( void ) const;
		void beSigned( Bureaucrat *b );
};

std::ostream &operator<<( std::ostream &os, Form &f );
