#include <iostream>
#include <string>
#include <iomanip>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone_number;
		std::string darkest_secret;

	public:
		Contact();
		~Contact();
		void	setFirst_name(std::string s);
		void	setLast_name(std::string s);
		void	setNickname(std::string s);
		void	setPhone_number(std::string n);
		void	setDarkest_secret(std::string s);
		std::string	getFirst_name();
		std::string	getLast_name();
		std::string	getNickname();
		std::string	getPhone_number();
		std::string	getDarkest_secret();
}; 