#pragma once
#include <fstream>
#include <unistd.h>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {

	private:
		std::string target;
		static std::string asciiTree;
	
	public:
		class FileError;

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		std::string getTarget();
		void writeFile() const;
		void execute(Bureaucrat const &executor) const;
};