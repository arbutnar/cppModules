#pragma once
#include <unistd.h>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	private:
		std::string	target;
	public:
		class RobotomyFailure;

		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &src );
        	RobotomyRequestForm &operator=( const RobotomyRequestForm &src );
		~RobotomyRequestForm( void );

		std::string getTarget( void );
		void robotomize( void ) const;
		void execute( Bureaucrat const &executor ) const;
};
