#include "FragTrap.hpp"

FragTrap::FragTrap( void )
	: ClapTrap() {
		std::cout << "\033[1;32mdefault FragTrap constructor\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name) {
		this->hp = 100;
		this->ep = 100;
		this->dp = 30;
		std::cout << "\033[1;32mFragTrap " << this->name << " constructed\033[0m" << std::endl;
}

FragTrap::~FragTrap( void ) {
		std::cout << "\033[1;32mFragTrap " << this->name << " deconstructed\033[0m" << std::endl;
}

void FragTrap::highFiveGuys(void) {
	if (this->ep > 0) {
		std::cout << "High five request" << std::endl;
		this->ep--;
	} else
		std::cout << "cannot request high five; insufficient energy point" << std::endl;
}