#pragma once
#include <fstream>
#include <unistd.h>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	private:
		std::string		target;
		static std::string	asciiTree;
	public:
		class FileError;

		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm &src );
        	ShrubberyCreationForm &operator=( const ShrubberyCreationForm &src );
		~ShrubberyCreationForm( void );

		std::string getTarget( void );
		void writeFile( void ) const;
		void execute( Bureaucrat const &executor ) const;
};
