#pragma once

#include <iostream>
#include <string>

enum Complains { DEBUG, INFO, WARNING, ERROR };

class Harl {
	public:
		Harl();
		~Harl();
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	complain(std::string level);
};
