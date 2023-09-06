#include "Phonebook.hpp"

int main() {
	std::string s;
	Phonebook phonebook;

	while (1) {
		std::cout << "type ADD, SEARCH or EXIT" << std::endl;
		std::cin >> s;
		if (s == "ADD")
			phonebook.add();
		else if (s == "SEARCH") {
			phonebook.contactList();
			phonebook.searchInfo();
		}
		else if (s == "EXIT")
			return 1;
		else
			std::cout << "Invalid insertion." << std::endl;
	}
	return 0;
}
