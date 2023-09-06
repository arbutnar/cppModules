#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
	: ClapTrap() {
		std::cout << "\033[1;32mdefault ScavTrap constructor\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name) {
		this->hp = 100;
		this->ep = 50;
		this->dp = 20;
		std::cout << "\033[1;32mScavTrap " << this->name << " constructed\033[0m" << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "\033[1;32mScavTrap " << this->name << " deconstructed\033[0m" << std::endl;
}

void	ScavTrap::attack (const std::string &target) {
	if (this->hp <= 0) {
		std::cout << "ScavTrap " << this->name << " dead" << std::endl;
		return ;
	}
	if (this->ep < 1) {
		std::cout << "ScavTrap " << this->name << "cannot attack; insufficient energy!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->dp << " points of damage!" << std::endl;
	this->ep -= 1;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " <<  this->name << " is in Gate keeper mode!" << std::endl;
}