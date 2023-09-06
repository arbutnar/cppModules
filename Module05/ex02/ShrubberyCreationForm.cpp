#include "ShrubberyCreationForm.hpp"

class ShrubberyCreationForm::FileError : public std::exception {
	public:
		virtual const char* what() const throw() { return ("\033[1;31mCannot open file\033[0m\n"); }
};

std::string ShrubberyCreationForm::asciiTree =
        "			'.,				\n"
        "			'b      *		\n"
        "			'$    #.		\n"
        "			$:   #:			\n"
        "			*#  (@):		\n"
        "			:@,(@):   ,.**:'\n"
        " ,			:@@*: 	..**'	\n"
        "	'#o..	.:(@)'	.@*'	\n"
        "		'bq,8..:,@@*'	,*	\n"
        "			,$q,:(@)'.p*'	\n"
        "			'@@Pp*'			\n"
        "			Y7'.'			\n"
        "			:(@):.			\n"
        "			..@@:'.			\n"
        "			..:@(@):.      	\n";

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), target (target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src.name, src.signGrade, src.execGrade) {
    *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
    if (this != &src) {
        this->target = src.target;
		this->asciiTree = src.asciiTree;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

std::string ShrubberyCreationForm::getTarget() {
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    try {
        writeFile();
        std::cout << executor.getName() << " successfully executed " << this->getName() << " form." << std::endl;
    } catch(std::exception &e) {
        std::cout << e.what() << " to execute" << std::endl;
    }
}

void ShrubberyCreationForm::writeFile() const {
    std::ofstream outFile;
    std::string filename = target + "_shrubbery";
	outFile.open(filename.c_str());
	
	if (!outFile.is_open())
		throw ShrubberyCreationForm::FileError();
	outFile << asciiTree;
    outFile.close();
}
