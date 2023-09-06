#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ScavTrap(), FragTrap(){
		FragTrap::hp = 100;
    	ScavTrap::ep = 50;
    	FragTrap::dp = 30;
		std::cout << "\033[1;34mDiamondTrap default constructor\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + " clap_name"), ScavTrap(name), FragTrap(name), name (name) {
		FragTrap::hp = 100;
    	ScavTrap::ep = 50;
    	FragTrap::dp = 30;
		std::cout << "\033[1;34mDiamondTrap " << this->name << " constructed\033[0m" << std::endl;
} 

DiamondTrap::DiamondTrap(const DiamondTrap &src) {
	std::cout << "\033[1;34mDiamondTrap copy constructor called\033[0m" << std::endl;
	*this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
	std::cout << "\033[1;34mDiamondTrap copy assignment operator\033[0m" << std::endl;
	if (this == &src)
		return (*this);
	this->ClapTrap::name = src.ClapTrap::name;
	this->ScavTrap::name = src.ScavTrap::name;
	this->FragTrap::name = src.FragTrap::name;
	this->name = src.name;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "\033[1;34mDiamondTrap " << this->name << " decostructed\033[0m" << std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "Am I " << this->name << '?' << std::endl;
	std::cout << "Or am I " << ClapTrap::name << "?\nThought I was me." << std::endl;
}