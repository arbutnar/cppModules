#include "Contact.hpp"

// a no initialized std::string it's empty as default

Contact::Contact() 
//: first_name {"None"}, last_name {"None"}, nickname {"None"}, phone_number {"None"}, darkest_secret {"None"} 
{
			first_name = "None";
			last_name = "None";
			nickname = "None";
			phone_number = "None";
			darkest_secret = "None";
};

Contact::~Contact() {

};

void	Contact::setFirst_name(std::string s) {
	first_name = s;
}

std::string	Contact::getFirst_name() {
	return (first_name);
}

void	Contact::setLast_name(std::string s) {
	last_name = s;
}

std::string	Contact::getLast_name() {
	return (last_name);
}

void	Contact::setNickname(std::string s) {
	nickname = s;
}

std::string	Contact::getNickname() {
	return (nickname);
}

void	Contact::setPhone_number(std::string s) {
	phone_number = s;
}

std::string	Contact::getPhone_number() {
	return (phone_number);
}

void	Contact::setDarkest_secret(std::string s) {
	darkest_secret = s;
}

std::string	Contact::getDarkest_secret() {
	return (darkest_secret);
}
