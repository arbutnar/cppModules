#include "FragTrap.hpp"

FragTrap::FragTrap( void )
	: ClapTrap() {
		std::cout << "\033[1;34mFragTrap default constructor for " << this->name << "\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name) {
		this->hp = 100;
		this->ep = 100;
		this->dp = 30;
		std::cout << "\033[1;34mFragTrap one-arg constructor for " << this->name << "\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) {
	std::cout << "\033[1;34mFragTrap copy constructor called\033[0m" << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
	std::cout << "\033[1;34mFragTrap copy constructor called\033[0m" << std::endl;
	if (this == &src)
		return (*this);
	this->name = src.name;
	return (*this);
}

FragTrap::~FragTrap( void ) {
		std::cout << "\033[1;34mFragTrap deconstructor for " << this->name << "\033[0m" << std::endl;
}

void	FragTrap::attack(const std::string &target) {
	if (this->hp <= 0) {
		std::cout << "FragTrap " << this->name << " dead" << std::endl;
		return ;
	}
	if (this->ep < 1) {
		std::cout << "FragTrap " << this->name << "cannot attack; insufficient energy!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->dp << " points of damage!" << std::endl;
	this->ep -= 1;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "High five request" << std::endl;
}