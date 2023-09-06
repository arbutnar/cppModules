#pragma once

#include <iostream>
#include <string>

class Weapon {

	private:
		std::string	type;
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		void	setType(std::string newtype);
		std::string	&getType(void);
};
