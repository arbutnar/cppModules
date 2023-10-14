#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		const	std::string name;
		bool	isSigned;
		const	int signGrade;
		const	int execGrade;
	public:
		class GradeTooLowException;
		class GradeTooHighException;
		class notSigned;
		
		AForm( void );
		AForm( std::string name, int signGrade, int execGrade );
		AForm( const AForm &src );
        	AForm &operator=( const AForm &src );
		virtual ~AForm( void );

		std::string getName( void ) const;
		bool getIsSigned( void ) const;
		void setIsSigned( bool state );
		int getSignGrade( void ) const;
		int getExecGrade( void ) const;
		void beSigned( Bureaucrat *b );

		virtual void execute( Bureaucrat const &executor ) const = 0;

};

std::ostream &operator<<( std::ostream &os, AForm &f );
