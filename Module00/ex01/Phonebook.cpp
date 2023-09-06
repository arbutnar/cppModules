#include "phonebook.hpp"

Phonebook::Phonebook() {
	i = 0;
};

Phonebook::~Phonebook() {

};

void	Phonebook::add() {
	std::string		s;

	std::cout << "Enter contact first name: ", std::cin >> s;
	contacts[i].setFirst_name(s);
	std::cout << "Enter contact last name: ", std::cin >> s;
	contacts[i].setLast_name(s);
	std::cout << "Enter contact nickname: ", std::cin >> s;
	contacts[i].setNickname(s);
	std::cout << "Enter contact phonenumber: ", std::cin >> s;
	contacts[i].setPhone_number(s);
	std::cout << "Enter contact darkest secret: ", std::cin >> s;
	contacts[i].setDarkest_secret(s);
	// if everything was entered then write success, otherwise write incomplete, just as warnings.
	i++;
	if (i == 8)
		i = 0;
}

void	Phonebook::contactList() {
	std::string	s;

	for (int index = 0; index < 8; index++) {
		std::cout << '|' << std::setw(10) << index + 1 << '|';
		s = contacts[index].getFirst_name();
		if (s.length() > 10)
			std::cout << s.substr(0, 9) << '.';
		else
			std::cout << std::setw(10) << s;
		std::cout << '|';
		s = contacts[index].getLast_name();
		if (s.length() > 10)
			std::cout << s.substr(0, 9) << '.';
		else
			std::cout << std::setw(10) << s;
		std::cout << '|';
		s = contacts[index].getNickname();
		if (s.length() > 10)
			std::cout << s.substr(0, 9) << '.';
		else
			std::cout << std::setw(10) << s;
		std::cout << '|' << std::endl;
	}
}

void	Phonebook::searchInfo() {
	int	index;
	std::string s;

	std::cout << "type BACK or INFO: ", std::cin >> s;
	if (s == "BACK")
		return ;
	else if (s == "INFO") {
		std::cout << "Digit index for contact full info: ", std::cin >> index;
		if (index < 1 || index > 8) {
			std::cout << "Invalid Index" << std::endl;
			return ;
		}
		s = contacts[index - 1].getFirst_name();
		std::cout << s << std::endl;
		s = contacts[index - 1].getLast_name();
		std::cout << s << std::endl;
		s = contacts[index - 1].getNickname();
		std::cout << s << std::endl;
		s = contacts[index - 1].getPhone_number();
		std::cout << s << std::endl;
		s = contacts[index - 1].getDarkest_secret();
		std::cout << s << std::endl;
	}
	else
		this->searchInfo();
}