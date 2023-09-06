#pragma once
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {

	private:
		std::string target;

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		~PresidentialPardonForm();

		std::string getTarget();
		void Zaphod() const;
		void execute(Bureaucrat const &executor) const;
};