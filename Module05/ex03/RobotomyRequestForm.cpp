#include "RobotomyRequestForm.hpp"

class RobotomyRequestForm::RobotomyFailure : public std::exception {
	public:
		virtual const char* what() const throw() { return ("\033[1;31mRobotomy failed\033[0m"); }
};

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm("RobotomyRequestForm", 72, 45), target (target) {
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src )
    : AForm(src.name, src.signGrade, src.execGrade) {
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &src ) {
    if (this != &src)
        this->target = src.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
}

std::string RobotomyRequestForm::getTarget( void ) {
	return (this->target);
}

void RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
	AForm::execute(executor);
	try {
		robotomize();
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void RobotomyRequestForm::robotomize( void ) const {
	srand((unsigned int)time(NULL));
    int num = rand() % 100;

	for (int i = 0; i < 2; ++i) {
		std::cout << "DrrrrrrrDrrrrDrrrrrrr ... ..." << std::endl;
		sleep(1);
    }
	if (num % 2 == 0)
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	else
		throw RobotomyFailure();
}
