#pragma once
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        int                grade;
        const std::string  name;
    public:
        class GradeTooLowException;
        class GradeTooHighException;

        Bureaucrat( std::string name, int grade );
        Bureaucrat( const Bureaucrat &src );
        Bureaucrat &operator=( const Bureaucrat &src );
        ~Bureaucrat( void );

        std::string getName( void ) const;
        int getGrade( void ) const ;
        void incrementGrade( int amount );
        void decrementGrade( int amount );

        void signForm( AForm &form );
        void executeForm( AForm const &form );
};

std::ostream &operator<<( std::ostream &os, Bureaucrat &b );
